

OS_INLINE tcp_server::tcp_server (void)
: socket_(AF_INET , SOCK_STREAM, IPPROTO_TCP )
{
	toString_ = _T("tcp_server - ") + socket_.toString();
}

OS_INLINE tcp_server::~tcp_server (void)
{
}

OS_INLINE base_socket& tcp_server::socket()
{
	return socket_;
}

OS_INLINE  const base_socket& tcp_server::socket() const
{
	return socket_;
}

OS_INLINE  const inet_address& tcp_server::bind_addr() const
{
	return bind_addr_;
}

OS_INLINE bool tcp_server::is_good() const
{
	return socket_.is_good();
}

OS_INLINE bool tcp_server::bind( const inet_address& addr)
{
#pragma warning(disable: 4267)
	if ( SOCKET_ERROR != ::bind( socket_.get_handle(), addr.addr(), addr.size() ) )
#pragma warning(default: 4267)
	{
		bind_addr_ = addr;
		toString_ = _T("tcp_server ") + socket_.toString() + _T(" ���� ") + bind_addr_.toString();
		return true;
	}
	return false;
}

OS_INLINE bool tcp_server::listen( int backlog )
{
	if( SOCKET_ERROR != ::listen( socket_.get_handle(), backlog ) )
	{
		toString_ = _T("tcp_server ") + socket_.toString() + _T(" ������ ") + bind_addr_.toString();
		return true;
	}
	return false;
}

OS_INLINE bool tcp_server::accept( tcp_client& accepted)
{
#pragma warning(disable: 4267)
	int len = accepted.remote_addr().size();
#pragma warning(default: 4267)
	accepted.socket().set_handle( ::accept( socket_.get_handle(),( sockaddr* ) accepted.remote_addr().addr(),&len ) );
	return accepted.is_good();
}

OS_INLINE bool tcp_server::accept(tcp_client& accepted
						, void* data_buffer
						, size_t data_len
						, size_t local_addr_len
						, size_t remote_addr_len
						, OVERLAPPED& overlapped )
{
	DWORD bytesReceived = 0;
#pragma warning(disable: 4267)
	return ( TRUE == base_socket::__acceptex( socket_.get_handle(), accepted.socket().get_handle(),data_buffer, data_len, local_addr_len, remote_addr_len, &bytesReceived, &overlapped ));
#pragma warning(default: 4267)
}

OS_INLINE void tcp_server::swap( tcp_server& r)
{
	bind_addr_.swap( r.bind_addr_ );
	socket_.swap( r.socket_ );
	toString_.swap( r.toString_ );
}

OS_INLINE const tstring& tcp_server::toString( ) const
{
	return toString_;
}