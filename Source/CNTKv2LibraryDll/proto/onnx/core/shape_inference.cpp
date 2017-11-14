#pragma warning(push)
#pragma warning(disable : 4800 4610 4512 4510 4267 4127 4125 4100 4456 4189 4996)

#include "shape_inference.h"

namespace ONNXIR
{
    InferenceContext::InferenceContext(Node* p_node,
        const OpSignature* p_opSchema)
        : m_node(p_node),
        m_opSignature(p_opSchema)
    {
    }

    const Node* InferenceContext::GetNode() const
    {
        return m_node;
    }

    const OpSignature* InferenceContext::GetOp() const
    {
        return m_opSignature;
    }

    const std::vector<NodeArg>* InferenceContext::GetInputs() const
    {
        if (nullptr == m_node)
        {
            return nullptr;
        }
        return &(m_node->InputDefs());
    }

    std::vector<NodeArg>* InferenceContext::Mutable_Outputs()
    {
        if (nullptr == m_node)
        {
            return nullptr;
        }
        return &(m_node->Mutable_OutputDefs());
    }
}

#pragma warning(pop)