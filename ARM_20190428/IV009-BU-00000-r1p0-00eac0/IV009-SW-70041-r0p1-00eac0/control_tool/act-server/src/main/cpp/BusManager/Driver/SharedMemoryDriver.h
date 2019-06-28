//----------------------------------------------------------------------------
//   The confidential and proprietary information contained in this file may
//   only be used by a person authorised under and to the extent permitted
//   by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//          (C) COPYRIGHT 2018 - 2019 ARM Limited or its affiliates
//              ALL RIGHTS RESERVED
//
//   This entire notice must be reproduced on all copies of this file
//   and copies of this file may only be made by a person if such person is
//   permitted to do so under the terms of a subsisting license agreement
//   from ARM Limited or its affiliates.
//----------------------------------------------------------------------------

#ifndef __SHARED_MEMORY_DRIVER_H__
#define __SHARED_MEMORY_DRIVER_H__

#include <ATL/ATLObject.h>
#include <ATL/ATLComponent.h>

#include <BusManager/BaseDriverInterface.h>

namespace act {

    class CSharedMemoryDriver : public virtual CBaseDriver, public virtual CATLObject {
    public:
        CSharedMemoryDriver() {}
        ~CSharedMemoryDriver();

        // IATLObject interface
        virtual const std::string GetObjectStaticName();

        // IATLComponent
        virtual const std::string GetName();
        virtual CATLError Initialize(const flags32& options = 0);
        virtual CATLError Open();
        virtual CATLError Close();
        virtual CATLError Terminate();

        // IDriver
        virtual CATLError ProcessPacket(TSmartPtr< CTransferPacket > packet, const flags32& options = 0);
        virtual const std::vector<std::string> GetDeviceList();
        virtual const std::vector<EPacketCommand> GetCommandList();
        virtual const EACTDriverMode GetCurrentMode();
        virtual const std::vector<EACTDriverMode> GetSupportedModes();

    private:
        // memory pointer
        UInt8* memory_ptr;
        std::string dev_name;
        basesize memory_size;
    };
}
#endif /* __SHARED_MEMORY_DRIVER_H__ */
