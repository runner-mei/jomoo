
#ifndef JOMOO_THREAD_MANAGER_CPP
#define JOMOO_THREAD_MANAGER_CPP

#include "config.h"

#if !defined (JOMOO_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* JOMOO_LACKS_PRAGMA_ONCE */

#include "config_threading.h"

#ifdef JOMOO_MT

_thread_begin

#ifndef OS_HAS_INLINED

#include "JOMOO_Thread_Manager.inl"

#endif // OS_HAS_INLINED

_thread_end

#endif // JOMOO_MT

#endif // JOMOO_THREAD_MANAGER_CPP