
#include "FixedPool.h"
#include "Windows.h"
#include <new>

_memory_begin



FixedPool::FixedPool( const tstring& name , size_t number, size_t size )
: lpvAddr_( 0 )
, chunk_size_( size )
, used_( 0 )
, number_( number )
, toString_( name )
{
	ASSERT( chunk_size_ > 0 );
	ASSERT( number_ > 0 );
	

	size_t CHUNK_SIZE = Hazel_LCD( CHUNK_HEAD_SIZE + chunk_size_ , sizeof( void* ) );
	lpvAddr_ = ::LocalAlloc(GPTR, Hazel_LCD(  CHUNK_SIZE * number_ , KB_SIZE ) );

	if( lpvAddr_ == 0 )
		ThrowException1( BadMemoryException, lastError() );

	for( size_t i = 0; i < number_ ; i ++ )
	{
		CHUNK* chunk = (CHUNK*)(( char*)lpvAddr_ + i * CHUNK_SIZE);
		chunk->magic_ = pool_magic_v;
		chunk->pointee_ = (( char*)chunk) + CHUNK_HEAD_SIZE;
		queue_.push( chunk );
	}

	toString_ += "[";
	toString_ += detail::to_string_t( number_ );
	toString_ += ":";
	toString_ += detail::to_string_t( chunk_size_ );
	toString_ += "]";
}

FixedPool::~FixedPool()
{
	::LocalFree( lpvAddr_ );
}

void* FixedPool::malloc ( const char* file, size_t line )
{
	CHUNK* p = queue_.pop();
	if( p == 0 )
		throw std::bad_alloc( (toString() + "> bad allocation").c_str() );
	return p->pointee_;
}

void FixedPool::free (void *chunk)
{
	CHUNK* p = ( CHUNK* ) ( ( (char*)chunk ) - CHUNK_HEAD_SIZE );
#ifdef FIXED_POOL_ASSERT
	ASSERT( p->magic_ == pool_magic_v );
#endif
	return queue_.push( p );
}

size_t FixedPool::chunk_size() const
{
	return chunk_size_;
}

void FixedPool::dump( std::ostream& Target ) const
{
}

const tstring& FixedPool::toString() const
{
	return toString_;
}


_memory_end