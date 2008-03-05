

JOMOO_INLINE
JOMOO_socket::JOMOO_socket (void)
{

}

JOMOO_INLINE
JOMOO_socket::~JOMOO_socket (void)
{

}

JOMOO_INLINE ssize_t
JOMOO_socket::recv (void *buf,
                   size_t len,
                   int flags ) const
{

	return ::recv ( this->get_handle (),
                    ( char* )buf,
                    ( int )len,
                    flags );
}

JOMOO_INLINE ssize_t
JOMOO_socket::recv (void *buf,
                   size_t len ) const
{

	return recv (  buf,
                    len,
                    0);
}
JOMOO_INLINE ssize_t
JOMOO_socket::recvv (iovec iov[],
                   size_t n) const
{

	DWORD NumberOfBytesRecvd = 0;
	DWORD Flags = 0;
	int r = WSARecv( get_handle()
		, iov
		, ( DWORD ) n
		, &NumberOfBytesRecvd
		, &Flags
		, 0
		, 0 );
	if( r == 0 )
		return  NumberOfBytesRecvd;
	return r;
}

JOMOO_INLINE bool
JOMOO_socket::recvv (iovec iov[],
					size_t n,
					JOMOO_OVERLAPPED& overlapped) const
{
	DWORD NumberOfBytesRecvd = 0;
	DWORD Flags = 0;
	return (WSARecv( get_handle()
		, iov
		, ( DWORD ) n
		, &NumberOfBytesRecvd
		, &Flags
		, &overlapped
		, 0 ) == 0 ) ? true : false;
}

JOMOO_INLINE bool
JOMOO_socket::recv (void *buf,
				   size_t n,
				   JOMOO_OVERLAPPED& overlapped) const
{
	DWORD bytes_read = 0;
	DWORD short_nbyte = static_cast < DWORD>( n);
	return ::ReadFile( ( HANDLE )this->get_handle ()
		, buf
		, short_nbyte
		, &bytes_read
		, &overlapped
		//, 0 
		) ? true : false ;
	//return r;
}

JOMOO_INLINE ssize_t
JOMOO_socket::send (const void *buf,
                   size_t len,
                   int flags ) const
{

    return ::send (get_handle(), (const char *) buf, ( int )len, flags);
}

JOMOO_INLINE ssize_t
JOMOO_socket::send (const void *buf,
                   size_t len ) const
{

    return ::send (get_handle(), (const char *) buf, ( int )len, 0);
}


JOMOO_INLINE bool 
JOMOO_socket::send (const void *buf,
				   size_t n,
				   JOMOO_OVERLAPPED& overlapped) const
{
	DWORD bytes_written;
	DWORD short_nbyte = static_cast< DWORD >( n);
	return ::WriteFile ( ( HANDLE ) get_handle(), buf, short_nbyte, &bytes_written, &overlapped) ? true : false;
}


JOMOO_INLINE ssize_t
JOMOO_socket::sendv ( const iovec iov[],
                    size_t n ) const
{
	DWORD bytes_sent = 0;
	int r = ::WSASend ( get_handle(),
		(WSABUF *) iov,
		( DWORD )n,
		&bytes_sent,
		0,
		0,
		0);
	if( r == 0 )
		return bytes_sent;
	return r;
}

JOMOO_INLINE   bool 
JOMOO_socket::sendv (const iovec iov[],
					size_t n,
					JOMOO_OVERLAPPED& overlapped) const
{
	DWORD bytes_sent = 0;
	return (::WSASend ( get_handle(),
		(WSABUF *) iov,
		( DWORD )n,
		&bytes_sent,
		0,
		&overlapped,
		0) == 0 ) ? true : false;
}

JOMOO_INLINE   bool 
JOMOO_socket::transmit (const iopack iov[],
                 size_t n,
                 JOMOO_OVERLAPPED& overlapped) const
{
#ifdef _WINXP_
	return ::TransmitPackets ( get_handle(),
		( iopack* )iov,
		( DWORD )n,
		0,
		&overlapped,
		0) ? true : false;
#else
	return sendv( iov, n ,overlapped );
#endif // _WINXP_
}