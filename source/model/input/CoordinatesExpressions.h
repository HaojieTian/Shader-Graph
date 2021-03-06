#ifndef SHADERGRAPH_COORDINATESEXPR_H
#define SHADERGRAPH_COORDINATESEXPR_H

#include <memory>

#include <core/Core.h>

#include "../Node.h"

#define SPINBOX_STEP 0.1
#define SPINBOX_VALUE_CHANGED_SLOT static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged)

namespace ShaderGraph
{
    class UVNode : public Node
    {
    Q_OBJECT

    public:
        UVNode();

        GLSLData nodeToGLSL() override
        {
            GLSLData buffer;
            GLSL_CODE(buffer.generatedCode,
                      "// Input : UV \n"
                      "{0} = texCoord; \n"
                      "{1} = texCoord.x; \n"
                      "{2} = texCoord.y; \n"
                      "\n",
                      autoName(outputs()[0]),
                      autoName(outputs()[1]),
                      autoName(outputs()[2]));
            return buffer;
        }
    };
}

#endif //SHADERGRAPH_COORDINATESEXPR_H
