#ifndef INAMINGSUBSYSTEM_H
# define INAMINGSUBSYSTEM_H

#include "config.h"

#if !defined (Hazel_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* Hazel_LACKS_PRAGMA_ONCE */

// Include files
# include "config_MicroKernel.h"
# include "Hazel.Base/Exception.HPP"
# include "Hazel.Base/collections/enumerator.H"
# include "IComponentModel.h"

_micro_kernel_begin

class IKernel;

class INamingSubSystem
{
public:

	typedef IComponentModel::key_type key_type;

	class NamingSubSystemException : public _hazel Exception
	{
	public:

		NamingSubSystemException( const   char* const         srcFile
			, size_t        srcLine
			, const key_type& key
			, const tstring& message )
			: _hazel Exception( srcFile, srcLine ,message )
			, guid_( key.guid() )
			, position_( key.position() )
		{
		}

		NamingSubSystemException( const   char* const         srcFile
			, size_t        srcLine
			, const key_type::guid_type& _guid
			, size_t _position
			, const tstring& message )
			: _hazel Exception( srcFile, srcLine ,message )
			, guid_( _guid )
			, position_( _position )
		{
		}

		const key_type::guid_type& guid() const
		{
			return guid_;
		}

		size_t position() const
		{
			return position_;
		}

		virtual Exception* clone()
		{
			return new NamingSubSystemException( *this );
		}

		virtual void rethrow()
		{
			Raise( *this );
		}

		virtual void print(std::ostream& Target ) const
		{
			Target << BT_TEXT( "NamingSubSystemException[" )
				<< what()
				<< BT_TEXT( "]" )
				<< std::endl;
			dumpFile( Target );
			Target << BT_TEXT( "\t[ guid =" )
				<< guid()
				<< BT_TEXT( ",position =" )
				<< position()
				<< BT_TEXT( " ]" );
		}
	private:
		key_type::guid_type guid_;
		size_t position_;
	};

	class walker_type
	{
	public:
		typedef IComponentModel value_type;

		virtual ~walker_type() {};
		virtual void on_walk( value_type& ) = 0;
		virtual void on_walk( const value_type& ) = 0;
	};

	typedef enumerator< walker_type > enumerator;
	typedef const_enumerator< walker_type > const_enumerator;

	virtual ~INamingSubSystem(){}

	/**
	 * ��ʼ��
	 */
	virtual void Initialize( IKernel& kernel ) = 0;

	/**
	* ȡ�����������
	* @param[ in ] key �����id��
	*/
	virtual ComponentModelPtr	find ( const key_type& key ) = 0;
	virtual ComponentModelConstPtr	find ( const key_type& key ) const = 0;

	/**
	* ����һ�����
	* @param[ in ] guid ���ID
	* @param[ in ] pos ����������е�λ��
	* @remarks ע�⣬���������һ�������󣬾Ͳ����������������ˣ�������������
	* �������������������������һ��ͬid������������ӳ�һ���쳣��
	*/
	virtual ComponentModelPtr&			add ( const key_type::guid_type& guid, size_t pos ) = 0;

	/**
	* ɾ��һ�����
	* @param[ in ] index �����id��
	* @remarks ע�⣬���������ϱ����١�
	*/
	virtual bool			remove ( const key_type& index ) = 0;

	/**
	* ����������ĸ���
	* @return ����ĸ���
	*/
	virtual size_t		size (void) const = 0;

	/**
	 * �������е�ComponentModel
	 */
	virtual void walk( walker_type& walker ) = 0;

	virtual void walk( walker_type& walker ) const = 0;

	virtual const tstring&		toString() const = 0;
};

_micro_kernel_end

#endif // INAMINGSUBSYSTEM_H