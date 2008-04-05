

#ifndef JOMOO_GET_LAST_ERROR_H
#define JOMOO_GET_LAST_ERROR_H

#include "jomoo/config.h"

#if !defined (JOMOO_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* JOMOO_LACKS_PRAGMA_ONCE */

#include "jomoo/string.hpp"

inline tstring get_last_error( DWORD code )
{
	LPVOID lpMsgBuf = 0;
	DWORD ret = FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM | 
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		code,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL );
	if ( ret <= 0 )
	{
		return tstring( ( const tchar* )"<��֪��>" );
	}

	LPTSTR s = (LPTSTR)lpMsgBuf;
	s[ ret ] = 0;
	if( s[ret - 1 ] == '\r' || s[ ret - 1 ] == '\n')
		s[ret - 1 ] = 0;
	if( s[ret - 2 ] == '\r' || s[ ret - 2 ] == '\n')
		s[ret - 2 ] = 0;

	tstring str =( const tchar* ) "[";

	char tmp[110] = "";
	_ultoa_s( code, tmp,110, 10 );
	str += ( const tchar* )tmp;
	str += ( const tchar* )"],";
	str += (LPTSTR)lpMsgBuf;
	// Free the buffer.
	LocalFree( lpMsgBuf );

	return str;
}

inline tstring get_last_error( )
{
	return get_last_error( ::GetLastError() );
}

inline tstring lastError( DWORD code )
{
	return get_last_error( code );
}

inline tstring lastError( )
{
	return get_last_error( ::GetLastError() );
}


#pragma warning(disable: 4996)
inline tstring get_c_error( int e )
{
	return _tcserror( e );
}
#pragma warning(default: 4996)

inline tstring get_c_error()
{
	return get_c_error( errno );
}


#endif //JOMOO_GET_LAST_ERROR_H