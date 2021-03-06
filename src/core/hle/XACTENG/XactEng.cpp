// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// ******************************************************************
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************

#define LOG_PREFIX CXBXR_MODULE::XACT


#include <core\kernel\exports\xboxkrnl.h>
#include "core\kernel\init\CxbxKrnl.h"
#include "common\Logging.h"
#include "core\kernel\support\Emu.h"
#include "EmuShared.h"
#include "core\hle\XACTENG\XactEng.h"

#include <mmreg.h>
#include <msacm.h>
#include <process.h>
#include <clocale>


// NOTES: For Xbox, the XACT library is a wrapper for DirectSound.
//		  It is not be necesarry to emulate the entire API because of 
//		  this, but atm only the functions containing low level code are being
//		  emulated.
//		  Only timing require a patch which is done in LLE.


// ******************************************************************
// * patch: XACTEngineCreate
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(XACTEngineCreate)
(
	X_XACT_RUNTIME_PARAMETERS* pParams, 
	X_XACTEngine** ppEngine
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pParams)
		LOG_FUNC_ARG(ppEngine)
		LOG_FUNC_END;

	// TODO: Any other form of initialization?

	*ppEngine = (X_XACTEngine*)ExAllocatePool(sizeof( X_XACTEngine ));

		
	
	RETURN(S_OK);
}

// ******************************************************************
// * EmuXACTEngineDoWork
// ******************************************************************
void WINAPI xbox::EMUPATCH(XACTEngineDoWork)()
{
	LOG_FUNC();

	// TODO: Anything else required here?
	// AFAIK, this function just calls DirectSoundDoWork()

	//
	//EmuDirectSoundDoWork();
	//

		
}

// ******************************************************************
// * EmuIXACTEngine_RegisterWaveBank
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_RegisterWaveBank)
(
	X_XACTEngine*		pThis,
	LPVOID				pvData,
	dword_xt				dwSize,
	X_XACTWaveBank**	ppWaveBank
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(pvData)
		LOG_FUNC_ARG(dwSize)
		LOG_FUNC_ARG(ppWaveBank)
		LOG_FUNC_END;

	// TODO: Implement

	*ppWaveBank = (X_XACTWaveBank*)ExAllocatePool(sizeof( X_XACTWaveBank ));

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_RegisterStreamedWaveBank
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_RegisterStreamedWaveBank)
(
	X_XACTEngine*							pThis,
	X_XACT_WAVEBANK_STREAMING_PARAMETERS*	pParams,
	X_XACTWaveBank**						ppWaveBank
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(pParams)
		LOG_FUNC_ARG(ppWaveBank)
		LOG_FUNC_END;

	// TODO: Implement

	*ppWaveBank = (X_XACTWaveBank*)ExAllocatePool(sizeof( X_XACTWaveBank ));

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_CreateSoundBank
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_CreateSoundBank)
(
	X_XACTEngine*		pThis,
	LPVOID				pvData,
	dword_xt				dwSize,
	X_XACTSoundBank**	ppSoundBank
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(pvData)
		LOG_FUNC_ARG(dwSize)
		LOG_FUNC_ARG(ppSoundBank)
		LOG_FUNC_END;

	// TODO: Implement

	*ppSoundBank = (X_XACTSoundBank*)ExAllocatePool(sizeof( X_XACTSoundBank ));

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_DownloadEffectsImage
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_DownloadEffectsImage)
(
	X_XACTEngine*		pThis,
	PVOID				pvData,
	dword_xt				dwSize,
	LPVOID				pEffectLoc,
	LPVOID*				ppImageDesc
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(pvData)
		LOG_FUNC_ARG(dwSize)
		LOG_FUNC_ARG(pEffectLoc)
		LOG_FUNC_ARG(ppImageDesc)
		LOG_FUNC_END;

	// TODO: Implement

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_CreateSoundSource
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_CreateSoundSource)
(
	X_XACTEngine*		pThis,
	dword_xt				dwFlags,
	X_XACTSoundSource** ppSoundSource
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(dwFlags)
		LOG_FUNC_ARG(ppSoundSource)
		LOG_FUNC_END;

	*ppSoundSource = (X_XACTSoundSource*)ExAllocatePool(sizeof( X_XACTSoundSource ));

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_EnableHeadphones
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_EnableHeadphones)
(
	X_XACTEngine*		pThis,
	bool_xt				fEnabled
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(fEnabled)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_SetListenerOrientation
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_SetListenerOrientation)
(
	X_XACTEngine*	pThis,
	float			xFront,
	float			yFront,
	float			zFront,
	float			xTop,
	float			yTop,
	float			zTop,
	dword_xt			dwApply
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(xFront)
		LOG_FUNC_ARG(yFront)
		LOG_FUNC_ARG(zFront)
		LOG_FUNC_ARG(xTop)
		LOG_FUNC_ARG(yTop)
		LOG_FUNC_ARG(zTop)
		LOG_FUNC_ARG(dwApply)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_SetListenerPosition
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_SetListenerPosition)
(
	X_XACTEngine*	pThis,
	float			x,
	float			y, 
	float			z,
	dword_xt			dwApply
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(x)
		LOG_FUNC_ARG(y)
		LOG_FUNC_ARG(z)
		LOG_FUNC_ARG(dwApply)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_SetListenerVelocity
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_SetListenerVelocity)
(
	X_XACTEngine*	pThis,
	float			x,
	float			y, 
	float			z,
	dword_xt			dwApply
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(x)
		LOG_FUNC_ARG(y)
		LOG_FUNC_ARG(z)
		LOG_FUNC_ARG(dwApply)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_SetMasterVolume
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_SetMasterVolume)
(
	X_XACTEngine*	pThis,
    word_xt			wCategory,
    long_xt			lVolume
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(wCategory)
		LOG_FUNC_ARG(lVolume)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_CommitDeferredSettings
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_CommitDeferredSettings)
(
	X_XACTEngine* pThis
)
{
	LOG_FUNC_ONE_ARG(pThis);

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTSoundBank_GetSoundCueIndexFromFriendlyName
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTSoundBank_GetSoundCueIndexFromFriendlyName)
(
	X_XACTEngine*		pThis,
	PCSTR				pFriendlyName,
	dword_xt*				pdwSoundCueIndex
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(pFriendlyName)
		LOG_FUNC_ARG(pdwSoundCueIndex)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTSoundBank_Play
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTSoundBank_Play)
(
	X_XACTSoundBank*	pThis,
	dword_xt				dwSoundCueIndex,
	X_XACTSoundSource*	pSoundSource,
	dword_xt				dwFlags,
	X_XACTSoundCue**	ppSoundCue
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(dwSoundCueIndex)
		LOG_FUNC_ARG(pSoundSource)
		LOG_FUNC_ARG(dwFlags)
		LOG_FUNC_ARG(ppSoundCue)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTSoundBank_Stop
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTSoundBank_Stop)
(
	X_XACTSoundBank*	pThis,
	dword_xt				dwSoundCueIndex,
	dword_xt				dwFlags,
	X_XACTSoundCue*		pSoundCue
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(dwSoundCueIndex)
		LOG_FUNC_ARG(dwFlags)
		LOG_FUNC_ARG(pSoundCue)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTSoundSource_SetPosition
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTSoundSource_SetPosition)
(
	X_XACTSoundSource*	pThis,
    float_xt				x,
    float_xt				y,
    float_xt				z,
    dword_xt				dwApply
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(x)
		LOG_FUNC_ARG(y)
		LOG_FUNC_ARG(z)
		LOG_FUNC_ARG(dwApply)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTSoundSource_SetVelocity
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTSoundSource_SetVelocity)
(
	X_XACTSoundSource*	pThis,
    float_xt				x,
    float_xt				y,
    float_xt				z,
    dword_xt				dwApply
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(x)
		LOG_FUNC_ARG(y)
		LOG_FUNC_ARG(z)
		LOG_FUNC_ARG(dwApply)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_RegisterNotification
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_RegisterNotification)
(
	X_XACTEngine*					pThis,
    PCXACT_NOTIFICATION_DESCRIPTION pNotificationDesc
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(pNotificationDesc)
		LOG_FUNC_END;

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_GetNotification
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_GetNotification)
(
	X_XACTEngine*					pThis,
    PCXACT_NOTIFICATION_DESCRIPTION pNotificationDesc,
    LPVOID						    pNotification
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(pNotificationDesc)
		LOG_FUNC_ARG(pNotification)
		LOG_FUNC_END;

	// TODO: The contents of XACT_NOTIFICATION can vary from one XDK to the next.
	// The definition for 4627 is different than 5558.

	RETURN(S_OK);
}

// ******************************************************************
// * EmuIXACTEngine_UnRegisterWaveBank
// ******************************************************************
xbox::hresult_xt WINAPI xbox::EMUPATCH(IXACTEngine_UnRegisterWaveBank)
(
	X_XACTEngine*	pThis,
    X_XACTWaveBank*	pWaveBank
)
{
	LOG_FUNC_BEGIN
		LOG_FUNC_ARG(pThis)
		LOG_FUNC_ARG(pWaveBank)
		LOG_FUNC_END;


	// Even though the documentation doesn't tell us much, I'm
	// assuming that after this function is called, the pointer
	// to IXACTWaveBank is released.

//	if(pWaveBank)
//		ExFreePool(pWaveBank);

	RETURN(S_OK);
}
