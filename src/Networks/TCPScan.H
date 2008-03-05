

#ifndef TCPSCAN_H
#define TCPSCAN_H

#include "config.h"

#if !defined (BOE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* BOE_LACKS_PRAGMA_ONCE */

#include "BOE_Export.H"

struct TCPack;

typedef struct TCPack* TCPackPtr;
/**
 * ��ʼ��DLL���ڵ������к���֮ǰ�ȵ�����
 * @return �ɹ�����0
 */
BT_Export_C int init_TCPack( );

/**
 * ����
 * @remark �ڵ�����֮��Ҫ�ڵ����κκ�����
 */
BT_Export_C void shutdown_TCPack( );

/**
 * ����һ��TCPack��������������
 * @return �ɹ����ض���ָ�룬ʧ�ܷ���0
 * @remark ע�⣬����һ��TCPack����ͬʱ���е������������ܳ���255������
 * ��TCPackͬʱ���е������������ܳ���ϵͳ��������( һ�㲻����1000��)��
 */
BT_Export_C TCPackPtr createTCPack();

/**
 * �ͷ�TCPack
 * @param[ in ] TCPack ����ָ��
 */
BT_Export_C void freeTCPack( TCPackPtr ptr );


enum TCPConnectStatus
{
	/// TCP�˿ڴ�
	Tcp_success  
	
	/// TCP�˿ڹر�
	,Tcp_error  

	/// TCP�˿����ӳ�ʱ
	,Tcp_timeout

	/// ��������
	,Tcp_other
};

/**
 * TCP���ӽ���Ļص����
 * ��һ������Ϊһ��TCPConnectStatusֵ����ʾ���ӵĽ��
 * �ڶ�������Ϊ�ô����ӵ�ip��ַ
 * ����������Ϊ�ô����ӵĶ˿ں�
 */
typedef void (*TCPConnectedHandler )( int ,u_long , u_short );

/**
 * ����TCP���ӽ���Ļص����
 * @param[ in ] ptr TCPack����ָ�룬������createTCPack������
 * @param[ in ] handler TCP���ӽ���Ļص����
 * @return �ɹ�����0��ʧ�ܷ��ط�0
 */
BT_Export_C int setTCPConnectedHandler( TCPackPtr ptr ,TCPConnectedHandler handler );

/**
 * ����TCP���ӽ���Ļص����
 * @param[ in ] ptr TCPack����ָ�룬������createTCPack������
 * @param[ in ] ipstr ����
 * @param[ in ] port �����˿�
 * @return �ɹ�����0��ʧ�ܷ��ط�0
 */
BT_Export_C int sendTCPConnectPack_str( TCPackPtr ptr , const char* ipstr, u_short port );

/**
 * ����TCP���ӽ���Ļص����
 * @param[ in ] ptr TCPack����ָ�룬������createTCPack������
 * @param[ in ] ipstr ����
 * @param[ in ] port �����˿�
 * @return �ɹ�����0��ʧ�ܷ��ط�0
 */
BT_Export_C int sendTCPConnectPack( TCPackPtr ptr , long ip, u_short port );

/**
 * ȡ��TCPack�����е�ǰ���ӳ��е�����״̬
 * @param[ in ] ptr TCPack����ָ�룬������createTCPack������
 * @param[ in ] milli_seconds ��ʱʱ��
 * @return �ɹ�����0��ʧ�ܷ���<0����ʱ����1
 * @remark ע�⣬�����ǰ���ӳ��е������з���ʱ�������Ϸ���0����õ����е�����
 * ����ͱ��������������ֱ������ʧ�ܻ�ʱ��
 */
BT_Export_C int getTCPConnectStatus( TCPackPtr ptr , u_long milli_seconds );


#endif // TCPSCAN_H