
#include "pro_config.h"
#include "jingxian/IOCPServer.h"

#ifdef _MEMORY_DEBUG
#undef THIS_FILE
#define new	   DEBUG_NEW  
#define malloc DEBUG_MALLOC  
static char THIS_FILE[] = __FILE__;  
#endif // _MEMORY_DEBUG

_jingxian_begin

IOCPServer::IOCPServer(void)
	: _toString( _T("IOCPServer") )
	, _isRunning( false )
{
}

IOCPServer::~IOCPServer(void)
{
}

void IOCPServer::connectWith(const tchar* endPoint
                            , BuildProtocol buildProtocol
                            , OnConnectError onConnectError
                            , void* context )
{
	StringArray<tchar> sa = split_with_string( endPoint, _T("://") );
	if( 2 != sa.size() )
	{
		ERROR( _logger, _T("尝试连接到 '") << endPoint 
			<< _T("' 时发生错误 - 地址格式不正确") );
		
		IllegalArgumentException error( _T("地址格式不正确!") ) 
		onConnectError( error, context)
		return ;
	}
	
    stdext::hash_map<tstring, IConnectionBuilder*>::iterator it = 
                                         _connectionBuilders.find( sa.ptr( 0 ) );
    if( it == _connectionBuilders.end() )
	{
		ERROR( _logger, _T("尝试连接到 '") << endPoint 
			<< _T("' 时发生错误 - 不能识别的协议‘") << sa.ptr(0) 
			<< _T("’") );
		
		tstring err = _T("不能识别的协议 - ");
		err += sa.ptr(0);
		err += _T("!");
		
		IllegalArgumentException error( err  ) 
		onConnectError( error, context)
		return ;
	}
    
	     
    it->second->connect( endPoint, buildProtocol, onConnectError, context );
}

IAcceptor* IOCPServer::listenWith(const tchar* endPoint
			, IProtocolFactory* protocolFactory)
{
	tstring addr = endPoint;
	stdext::hash_map<tstring,IAcceptor*>::iterator acceptorIt = _acceptors.find( addr );
	if( _acceptors.end() != acceptorIt )
	{
		TRACE( _logger, _T("已经创建过监听器 '") << endPoint 
			<< _T("' 了!") );
		return acceptorIt->second;
	}
	
	StringArray<tchar> sa = split_with_string( endPoint, "://" );
	if( 2 != sa.size() )
	{
		ERROR( _logger, _T("尝试监听地址 '") << endPoint 
			<< _T("' 时发生错误 - 地址格式不正确!") );
		 return NULL;
	}
    stdext::hash_map<tstring, IAcceptorFactory*>::iterator it =
                                      _acceptorFactory.find( sa.ptr( 0 ) );
    if( it == _acceptorFactory.end() )
	{
		ERROR( _logger, _T("尝试监听地址 '") << endPoint 
			<< _T("' 时发生错误 - 不能识别的协议‘") << sa.ptr(0) 
			<< _T("’") );
	     return NULL;
	}
	     
    auto_ptr< IAcceptor> acceptor = it->second->createAcceptor( endPoint );
    
    if( acceptor->startListening() )
	{
		TRACE( _logger, _T("尝试监听地址 '") << endPoint 
			<< _T("' 时发生错误‘") << lastError()
			<< _T("’") );
		return NULL;
    }
	
    TRACE( _logger, _T("尝试监听地址 '") << endPoint 
		<< _T("' 成功‘") << sa.ptr(0) 
		<< _T("’") );
	
    _acceptors[ add ] = acceptor.get();
    
    return acceptor.release();
}
	
bool IOCPServer::send( IRunnable* runnable )
{
	return _proactor.send( _proactor.createRunnableCommand( runnable ) );
}
	
void IOCPServer::runForever()
{
	_isRunning = true;
	while( _isRunning )
	{
		if( 1 ==  _proactor.handle_events() )
			onIdle();
	}
}
	
void IOCPServer::interrupt()
{
	_isRunning = false;
}
	
bool IOCPServer::bind(HANDLE systemHandler)
{
	_paroactor.bind(systemHandler);
}

void IOCPServer::onIdle()
{
	
}
	
const tstring& IOCPServer::toString() const
{
	return _toString;
}


_jingxian_end
