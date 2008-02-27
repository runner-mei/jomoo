#ifndef _DbExecute_SQLITE_h_
#define _DbExecute_SQLITE_h_

#include "../../util/Variant.h"
#include "../../util/pTime.h"
#include "DbExecute.h"
#include "QSqlite.h"

_bt_begin

class DbConnection_SQLITE;

class DbExecute_SQLITE : public DbExecute2
{
public:
	DbExecute_SQLITE( DbConnection_SQLITE* con );
	~DbExecute_SQLITE();

	bool prepare( const tchar* sql, size_t len, bool reportWarningsAsErrors = true );
	bool prepare( const tstring& sql, bool reportWarningsAsErrors = true );
	bool exec( );
	bool reset( );

	bool bind( int index, int value );
	bool bind( int index, __int64 value );
	bool bind( int index, double value );
	bool bind( int index, const char* str , size_t n);
	bool bind( int index, const wchar_t* str , size_t n );
	bool bind( int index, const ptime& time );

	bool bind( const tstring& name, int value );
	bool bind( const tstring& name, __int64 value );
	bool bind( const tstring& name, double value );
	bool bind( const tstring& name, const char* str , size_t n );
	bool bind( const tstring& name, const wchar_t* str , size_t n );
	bool bind( const tstring& name, const ptime& time );

	bool bind( const tchar* name, size_t len, int value );
	bool bind( const tchar* name, size_t len, __int64 value );
	bool bind( const tchar* name, size_t len, double value );
	bool bind( const tchar* name, size_t len, const char* str , size_t n );
	bool bind( const tchar* name, size_t len, const wchar_t* str , size_t n );
	bool bind( const tchar* name, size_t len, const ptime& time );

	int affected_rows( );
	bool direct_exec( const tchar* sql, size_t len , bool reportWarningsAsErrors );
	bool direct_exec( const tstring& sql, bool reportWarningsAsErrors );

private:

	DbConnection_SQLITE *con_;

	const tchar* tail_;
	//
	sqlite3_stmt   *stmt_;

	std::list< tstring > buffer_;
};


_bt_end

#endif // _DbExecute_SQLITE_h_