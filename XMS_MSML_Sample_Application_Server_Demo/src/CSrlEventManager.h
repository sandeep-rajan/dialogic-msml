///////////////////////////////////////////////////////////////////////////////
//
// Copyright � 2006-2012 Dialogic Inc. All Rights Reserved.
//
// The source code contained or described herein and all documents related to
// the source code (collectively "Material") are owned by Dialogic Inc.,
// its subsidiaries, affiliates, suppliers, licensors and/or assigns 
// ("Dialogic"). Title to the Material remains with Dialogic. The Material 
// contains proprietary information and material of Dialogic. The Material is 
// protected by worldwide copyright, trade secret laws, treaty provisions 
// and/or other applicable intellectual property rights, laws and/or treaties.
// No part of the Material may be used, copied, reproduced, modified, 
// published, uploaded, posted, transmitted, distributed, or disclosed in any 
// way without Dialogic's prior express written permission.
//
// No license under any patent, copyright, trade secret or other intellectual
// property right is granted to or conferred upon you by disclosure or delivery
// of the Material, either expressly, by implication, inducement, estoppels
// or otherwise. Any license under such intellectual property rights must be
// express and approved by Dialogic in writing.
//
///////////////////////////////////////////////////////////////////////////////
// File Name: CSrlEventManager.h
//
// Description: CSrlEventManager class declaration
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CSrlEventManager_h
#define CSrlEventManager_h

#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>

#include "TypeDefs.h"
#include "ASrlEventManager.h"
#include "ADispatcher.h"
#include "Singleton.h"

#include <list>

#include <gcip.h>
#include <srllib.h>

class ASrlEvent;

///////////////////////////////////////////////////////////////////////////////
// Class: ::CSrlEventManager
//
// Description: The SRL Event Manager is responsible for handling all SRL and 
// GC events by saving event data and dispatching event tasks to the target 
// objects.
//
///////////////////////////////////////////////////////////////////////////////
class CSrlEventManager : public ASrlEventManager, public ADispatcher, public Singleton<CSrlEventManager>
{
   friend class Singleton<CSrlEventManager>;

public:
   virtual ~CSrlEventManager();
   const char* ClassName();

private:
   CSrlEventManager();
   CSrlEventManager( CTaskProcessorSptr a_taskProcessor);

   int PrimStart();
   int PrimOnStarted( int a_result);
   int PrimStop();
   int PrimOnStopped( int a_result);

   boost::shared_ptr<boost::thread> m_thread;

   void ProcessEvents();

   void LogGcError( const char* a_method, int a_deviceHandle);

};

#endif

