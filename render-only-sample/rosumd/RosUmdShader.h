#pragma once

#include "d3dumddi_.h"
//#include "D3d10tokenizedprogramformat.hpp"
#include "RosUmdDevice.h"

class RosUmdShader
{
public:

    RosUmdShader(RosUmdDevice * pDevice)
        : m_pDevice(pDevice)
    {
    }

    virtual ~RosUmdShader()
    {
    }

    static RosUmdShader* CastFrom(D3D10DDI_HSHADER);
    D3D10DDI_HSHADER CastTo() const;

    void Standup(const UINT * pCode, D3D10DDI_HRTSHADER hRTShader);
    virtual void Teardown();

    RosUmdResource * GetCodeResource()
    {
        return &m_hwShaderCode;
    }

protected:

    UINT *                          m_pCode;
    D3D10DDI_HRTSHADER              m_hRTShader;

    RosUmdDevice *                  m_pDevice;
    RosUmdResource                  m_hwShaderCode;
};

inline RosUmdShader* RosUmdShader::CastFrom(D3D10DDI_HSHADER hShader)
{
    return static_cast< RosUmdShader* >(hShader.pDrvPrivate);
}

inline D3D10DDI_HSHADER RosUmdShader::CastTo() const
{
    return MAKE_D3D10DDI_HSHADER(const_cast< RosUmdShader* >(this));
}

class RosUmdPipelineShader : public RosUmdShader
{
public:

    RosUmdPipelineShader(RosUmdDevice *pDevice)
        : RosUmdShader(pDevice)
    {
    }

    virtual ~RosUmdPipelineShader()
    {
    }

    static RosUmdPipelineShader* CastFrom(D3D10DDI_HSHADER);
    D3D10DDI_HSHADER CastTo() const;

    void Standup(const UINT * pCode, D3D10DDI_HRTSHADER hRT, const D3D11_1DDIARG_STAGE_IO_SIGNATURES * pSignatures);
    void Teardown();

private:

    UINT                            m_numInputSignatureEntries;
    D3D11_1DDIARG_SIGNATURE_ENTRY * m_pInputSignatureEntries;
    UINT                            m_numOutputSignatureEntries;
    D3D11_1DDIARG_SIGNATURE_ENTRY * m_pOutputSignatureEntries;

};

inline RosUmdPipelineShader* RosUmdPipelineShader::CastFrom(D3D10DDI_HSHADER hShader)
{
    return dynamic_cast<RosUmdPipelineShader*>(static_cast< RosUmdShader* >(hShader.pDrvPrivate));
}

inline D3D10DDI_HSHADER RosUmdPipelineShader::CastTo() const
{
    return MAKE_D3D10DDI_HSHADER(const_cast< RosUmdPipelineShader* >(this));
}

class RosUmdTesselationShader : public RosUmdShader
{
public:

    RosUmdTesselationShader(RosUmdDevice *pDevice)
        : RosUmdShader(pDevice)
    {
    }

    virtual ~RosUmdTesselationShader()
    {
    }

    static RosUmdTesselationShader* CastFrom(D3D10DDI_HSHADER);
    D3D10DDI_HSHADER CastTo() const;

    void Standup(const UINT * pCode, D3D10DDI_HRTSHADER hRTShader, const D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES * pSignatures);
    void Teardown();

private:

    UINT                                m_numInputSignatureEntries;
    D3D11_1DDIARG_SIGNATURE_ENTRY *     m_pInputSignatureEntries;
    UINT                                m_numOutputSignatureEntries;
    D3D11_1DDIARG_SIGNATURE_ENTRY *     m_pOutputSignatureEntries;
    UINT                                m_numPatchConstantSignatureEntries;
    D3D11_1DDIARG_SIGNATURE_ENTRY *     m_pPatchConstantSignatureEntries;

};

inline RosUmdTesselationShader* RosUmdTesselationShader::CastFrom(D3D10DDI_HSHADER hShader)
{
    return dynamic_cast<RosUmdTesselationShader*>(static_cast< RosUmdShader* >(hShader.pDrvPrivate));
}

inline D3D10DDI_HSHADER RosUmdTesselationShader::CastTo() const
{
    return MAKE_D3D10DDI_HSHADER(const_cast< RosUmdTesselationShader* >(this));
}
