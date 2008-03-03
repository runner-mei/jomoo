// Communication


#ifndef __Hazel_Transport__
#define __Hazel_Transport__

#include "config.h"

#if !defined (Hazel_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* Hazel_LACKS_PRAGMA_ONCE */

// Include files
#include "../config_Networks.h"
#include "Transport_Result.H"

_networks_begin

class Hazel_Transport;
class Hazel_Transport_Handler;

typedef counter_ptr< Hazel_Transport > Hazel_Transport_Ptr;

class Hazel_Read_Result : virtual public Hazel_Transport_Result
{

public:

	typedef Hazel_Transport_Handler handler_type;
	typedef Hazel_Transport transport_type;

	/**
	 * virtual destructor
	 */
	virtual ~Hazel_Read_Result(){}

	/**
	 * ȡ��ʵ�ʶ��������ݿ��С
	 * @return ʵ�ʶ��������ݿ��С
	 */
	virtual size_t bytes_to_transferred() const = 0;

	/**
	 * ȡ�����ݿ�Ļ���
	 * @return ���ݻ����ָ��
	 */
	virtual void* buffer() = 0;

	/**
	 * ȡ�����ݿ�Ļ���
	 * @return ���ݻ����ָ��
	 */
	virtual const void* buffer() const = 0;

	/**
	 * ȡ�����ݻ���Ĵ�С
	 * @return ���ݻ���Ĵ�С
	 */
	virtual size_t length() const = 0;

	/**
	 * �����첽�����Ļص����
	 */
	virtual Hazel_Transport_Handler& handle() = 0;

	/**
	 * �����첽������transport���
	 */
	virtual Hazel_Transport& transport() = 0;

};// END CLASS DEFINITION Hazel_Read_Result


class Hazel_Read_Array_Result : virtual public Hazel_Transport_Result
{

public:

	typedef Hazel_Transport_Handler handler_type;
	typedef Hazel_Transport transport_type;

	/**
	 * virtual destructor
	 */
	virtual ~Hazel_Read_Array_Result(){}

	/**
	 * ȡ��ʵ�ʶ��������ݿ��С
	 * @return ʵ�ʶ��������ݿ��С
	 */
	virtual size_t bytes_to_transferred() const = 0;

	/**
	 * ȡ�����ݻ���������
	 * @return �ɹ��������ݻ����������ָ�룬ʧ�ܷ���0
	 */
	virtual iovec* data() = 0;
	
	/**
	 * ȡ�����ݻ����������С
	 * @return ���ݻ����������С
	 */
	virtual size_t size() const = 0;

	/**
	 * �����첽�����Ļص����
	 */
	virtual Hazel_Transport_Handler& handle() = 0;

	/**
	 * �����첽������transport���
	 */
	virtual Hazel_Transport& transport() = 0;

};// END CLASS DEFINITION Hazel_Read_Array_Result



class Hazel_Write_Result : virtual public Hazel_Transport_Result
{

public:
		
	typedef Hazel_Transport_Handler handler_type;
	typedef Hazel_Transport transport_type;

	/**
	 * virtual destructor
	 */
	virtual ~Hazel_Write_Result(){}

	/**
	 * ȡ��ʵ�ʷ��͵����ݴ�С
	 * @return ʵ�ʷ��͵����ݴ�С
	 */
	virtual size_t bytes_to_transferred() const = 0;

	/**
	 * ȡ�����ݿ�Ļ���
	 * @return ���ݻ����ָ��
	 */
	virtual const void* buffer() const = 0;

	/**
	 * ȡ�����ݻ���Ĵ�С
	 * @return ���ݻ���Ĵ�С
	 */
	virtual size_t length() const = 0;

	/**
	 * �����첽�����Ļص����
	 */
	virtual Hazel_Transport_Handler& handle() = 0;

	/**
	 * �����첽������transport���
	 */
	virtual Hazel_Transport& transport() = 0;

};// END CLASS DEFINITION Hazel_Write_Result


class Hazel_Write_Array_Result : virtual public Hazel_Transport_Result
{

public:
		
	typedef Hazel_Transport_Handler handler_type;
	typedef Hazel_Transport transport_type;

	/**
	 * virtual destructor
	 */
	virtual ~Hazel_Write_Array_Result(){}

	/**
	 * ȡ��ʵ�ʶ��������ݿ��С
	 * @return ʵ�ʶ��������ݿ��С
	 */
	virtual size_t bytes_to_transferred() const = 0;

	/**
	 * ȡ�����ݻ���������
	 * @return �ɹ��������ݻ����������ָ�룬ʧ�ܷ���0
	 */
	virtual const iovec* data() = 0;

	/**
	 * ȡ�����ݻ����������С
	 * @return ���ݻ����������С
	 */
	virtual size_t size() const= 0;

	/**
	 * �����첽�����Ļص����
	 */
	virtual Hazel_Transport_Handler& handle() = 0;

	/**
	 * �����첽������transport���
	 */
	virtual Hazel_Transport& transport() = 0;

};// END CLASS DEFINITION Hazel_Transmit_Result



class Hazel_Transmit_Result : virtual public Hazel_Transport_Result
{

public:
		
	typedef Hazel_Transport_Handler handler_type;
	typedef Hazel_Transport transport_type;

	/**
	 * virtual destructor
	 */
	virtual ~Hazel_Transmit_Result(){}

	/**
	 * ȡ��ʵ�ʶ��������ݿ��С
	 * @return ʵ�ʶ��������ݿ��С
	 */
	virtual size_t bytes_to_transferred() const = 0;

	/**
	 * ȡ�����ݻ���������
	 * @return �ɹ��������ݻ����������ָ�룬ʧ�ܷ���0
	 */
	virtual const iopack* data() = 0;

	/**
	 * ȡ�����ݻ����������С
	 * @return ���ݻ����������С
	 */
	virtual size_t size() const= 0;

	/**
	 * �����첽�����Ļص����
	 */
	virtual Hazel_Transport_Handler& handle() = 0;

	/**
	 * �����첽������transport���
	 */
	virtual Hazel_Transport& transport() = 0;

};// END CLASS DEFINITION Hazel_Transmit_Result


/**
 * @Brief Hazel_Transport_Handler channel �첽�ص��ӿڣ�@see Hazel_Transport
 */
class Hazel_Transport_Handler
{

public:
	typedef counter_ptr< Hazel_Transport_Handler > ptr_type;
	typedef Hazel_Read_Result read_result_type;
	typedef Hazel_Read_Array_Result read_array_result_type;
	typedef Hazel_Write_Result write_result_type;
	typedef Hazel_Write_Array_Result write_array_result_type;
	typedef Hazel_Transmit_Result transmit_result_type;
	typedef Hazel_Transport transport_type;


	/**
	 * virtual destructor
	 */
	virtual ~Hazel_Transport_Handler(){}

	/**
	 * channel�������ص��ӿ�
	 * @see Hazel_Read_Result
	 * @see Hazel_Transport::read
	 */
	virtual void onRead(read_result_type& result) = 0;

	/**
	 * channel�������ص��ӿ�
	 * @see Hazel_Read_Array_Result
	 * @see Hazel_Transport::read
	 */
	virtual void onReadArray(read_array_result_type& result ) = 0;

	/**
	 * channelд�����ص��ӿ�
	 * @see Hazel_Write_Result
	 * @see Hazel_Transport::write
	 */
	virtual void onWrite(write_result_type& result) = 0;

	/**
	 * channelд�����ص��ӿ�
	 * @see Hazel_Write_Result
	 * @see Hazel_Transport::write
	 */
	virtual void onWriteArray(write_array_result_type& result) = 0;

	/**
	 * channelд�����ص��ӿ�
	 * @see Hazel_Transmit_Result
	 * @see Hazel_Transport::transmit
	 */
	virtual void onTransmit(transmit_result_type& result ) = 0;

	/**
	 * ȡ��ʵ��������
	 */
	virtual const tstring& toString() const = 0;

};// END CLASS DEFINITION handler_type

class Hazel_Transport
{
public:

	typedef counter_ptr< Hazel_Transport > ptr_type;

	typedef NetWorksLoggerPtr LoggerPtr;
	typedef Hazel_Transport_Handler handler_type;


	/**
	 * virtual destructor
	 */
	virtual ~Hazel_Transport(){}

	/**
	 * ����һ�����ݣ�ע�������첽��  )
	 * @param[ in ] handle �첽�ص��ӿ�,�����ݷ��Ͳ��������ܳɹ���ʧ�ܣ�������
	 *				���óɹ�������ص�handle��onWrite�ӿ�
	 * @param[ in ] buffer �����͵����ݿ�ָ��
	 * @param[ in ] length �����͵����ݿ��С
	 * @param[ in ] act ���β����ĵ�key
	 * @return �ɹ������첽�����򷵻�true,���򷵻�false
	 * @remark ע��������سɹ��������������ݱ����ͣ�Ҳ����������һ���ᷢ�ͳ�
	 *		   ������һ����ص�handle��onWrite�ӿڣ��������ʧ����һ����
	 *		   �����handle��onWrite�ӿ�
	 * @see Hazel_Transport_Handler
	 */
	virtual bool write(handler_type& handle,
				   const void* buffer,
				   size_t length,
				   void* act ) = 0;

	/**
	 * ���Ͷ�����ݣ�ע�������첽��  )
	 * @param[ in ] handle �첽�ص��ӿ�,�����ݷ��Ͳ��������ܳɹ���ʧ�ܣ�������
	 *				���óɹ�������ص�handle��onTransmit�ӿ�
	 * @param[ in ] data �����͵����ݿ�ָ��
	 * @param[ in ] size �����͵����ݿ����
	 * @param[ in ] act ���β����ĵ�key
	 * @return �ɹ������첽�����򷵻�true,���򷵻�false
	 * @remark ע��������سɹ��������������ݱ����ͣ�Ҳ����������һ���ᷢ�ͳ�
	 *		   ������һ����ص�handle��onTransmit�ӿڣ��������ʧ����һ��
	 *		   �������handle��onTransmit�ӿ�
	 * @see Hazel_Transport_Handler
	 */
	virtual bool write(handler_type& handle,
					  const iovec* data,
					  size_t size,
				   void* act ) = 0;
#ifndef ___iopack___
	/**
	 * �����ļ���ע�������첽��  )
	 * @param[ in ] handle �첽�ص��ӿ�,�����ݷ��Ͳ��������ܳɹ���ʧ�ܣ�������
	 *				���óɹ�������ص�handle��onTransmit�ӿ�
	 * @param[ in ] data �����͵����ݿ�ָ��
	 * @param[ in ] size �����͵����ݿ����
	 * @param[ in ] act ���β����ĵ�key
	 * @return �ɹ������첽�����򷵻�true,���򷵻�false
	 * @remark ע��������سɹ��������������ݱ����ͣ�Ҳ����������һ���ᷢ�ͳ�
	 *		   ������һ����ص�handle��onTransmit�ӿڣ��������ʧ����һ��
	 *		   �������handle��onTransmit�ӿ�
	 * @see Hazel_Transport_Handler
	 */
	virtual bool transmit(handler_type& handle,
					  const iopack* data,
					  size_t size,
				   void* act ) = 0;
#endif

	/**
	 * ��һ�����ݣ�ע�������첽��  )
	 * @param[ in ] handle �첽�ص��ӿ�,�����ݷ��Ͳ��������ܳɹ���ʧ�ܣ�������
	 *				���óɹ�������ص�handle��onRead�ӿ�
	 * @param[ in ] buffer �����ݵĻ���ָ��
	 * @param[ in ] length �����ݵĻ����С
	 * @param[ in ] act ���β����ĵ�key
	 * @return �ɹ������첽���򷵻�true,���򷵻�false
	 * @remark ע��������سɹ������������������ݣ�Ҳ������һ����������ݣ�
	 *		   ��һ����ص�handle��onRead�ӿڣ��������ʧ����һ������
	 *		   ����handle��onRead�ӿ�
	 * @see Hazel_Transport_Handler
	 */
	virtual bool read(handler_type& handle,
				  void* buffer,
				  size_t length,
				   void* act ) = 0;

	/**
	 * ��������ݣ�ע�������첽��  )
	 * @param[ in ] handle �첽�ص��ӿ�,�����ݷ��Ͳ��������ܳɹ���ʧ�ܣ�������
	 *				���óɹ�������ص�handle��onReadArray�ӿ�
	 * @param[ in ] data �����ݵĻ��������ָ��
	 * @param[ in ] length �����ݵĻ��������С
	 * @param[ in ] act ���β����ĵ�key
	 * @return �ɹ������첽���򷵻�true,���򷵻�false
	 * @remark ע��������سɹ������������������ݣ�Ҳ������һ����������ݣ�
	 *		   ��һ����ص�handle��onReadArray�ӿڣ��������ʧ����һ
	 *		   ���������handle��onReadArray�ӿ�
	 * @see Hazel_Transport_Handler
	 */
	virtual bool read(handler_type& handle,
				  iovec* data,
				  size_t size,
				   void* act ) = 0;

	/**
	 * ����channel����
	 * @param[ in ] option ������
	 * @param[ in ] value ����ֵ
	 * @return �ɹ�����0,���ɹ����ط� 0
	 */
	virtual int setFeature(const char* feature,
						bool value) = 0;

	/**
	 * ȡ��channel����
	 * @param[ in ] option ������
	 * @param[ in ] value ����ֵ
	 * @return �ɹ�����0,���ɹ����ط� 0
	 */
	virtual int getFeature(const char* feature,
						bool& value) const = 0;

	/**
	 * ����channelѡ��
	 * @param[ in ] option ѡ����
	 * @param[ in ] value ѡ��ֵ��buffer
	 * @param[ in ] size ѡ��ֵ��buffer�Ĵ�С
	 * @return �ɹ�����0,���ɹ����ط� 0
	 */
	virtual int setOption(const char* option,
					   void* value,
					   size_t size) = 0;

	/**
	 * ȡ��channelѡ��
	 * @param[ in ] option ѡ����
	 * @param[ in ] value ѡ��ֵ��buffer
	 * @param[ in/out ] size ѡ��ֵ��buffer�Ĵ�С
	 * @return �ɹ�����0,���ɹ����ط� 0
	 */
	virtual int getOption(const char* option,
					   void* value,
					   size_t& size) const = 0;

	///**
	// * ȡ�ñ��ص�ַ
	// * @return ���ص�ַ
	// */
	//virtual const Hazel_INET_Addr& getLocalAddr() const = 0;

	///**
	// * ȡ��Զ�̵�ַ
	// * @return Զ�̵�ַ
	// */
	//virtual const Hazel_INET_Addr& getRemoteAddr() const = 0;

	/**
	 * ������ǰ����
	 * @return �ɹ�����true,���ɹ�����false
	 */
	virtual bool cancel() = 0;

	/**
	 * ȡ�ø�ͨ������־����
	 */
	virtual LoggerPtr getLogger() = 0;

	/**
	 * ȡ��ʵ��������
	 */
	virtual const tstring& toString() const = 0;

};// END CLASS DEFINITION Hazel_Transport



_networks_end

#endif // __Hazel_Transport__