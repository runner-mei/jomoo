
#ifndef SEAL_KERNEL_ICOMPONENT_LOADER_H
# define SEAL_KERNEL_ICOMPONENT_LOADER_H

#include "config.h"

#if !defined (Hazel_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* Hazel_LACKS_PRAGMA_ONCE */

// Include files
#include "config_MicroKernel.h"
#include "IKernel.h"
#include "Hazel.Base/Exception.hpp"

_micro_kernel_begin

class IComponentLoader : public IComponent
{
    DECLARE_SEAL_COMPONENT( IComponentLoader, "SEAL/Kernel/Component/ComponentLoader" );
public:
	virtual ~IComponentLoader( ){}

	/**
	 * ����ָ���������ָ��������
	 * @param[ in ] into �������
	 * @param[ in ] componentKey ���������
	 * @param[ in ] key �����key
	 * @return �ɹ������������true�� ���򷵻�false
	 */
    virtual bool load ( IKernel& into, const tstring &componentKey, int key = 0 ) = 0;

	/**
	 * ����ָ����������е������ָ��������
	 * @param[ in ] into �������
	 * @param[ in ] componentKey ��������
	 * @return �ɹ������������true�� ���򷵻�false
	 */
	virtual bool loadAll (IKernel& into, const tstring &componentKey ) = 0;

	/**
	 * ����ָ�����������������ڵ�����
	 * @param[ in ] componentKey ��������
	 * @param[ in ] key �����key
	 * @return �ɹ������������true�� ���򷵻�false
	 */
	virtual bool load ( const tstring &componentKey, int key ) = 0;

	/**
	 * ����ָ����������е��������������ڵ�����
	 * @param[ in ] componentKey ��������
	 * @return �ɹ������������true�� ���򷵻�false
	 */
	virtual bool loadAll ( const tstring &componentKey ) = 0;
};

_micro_kernel_end

#endif // SEAL_KERNEL_ICOMPONENT_LOADER_H