//-----------------------------------------------------------------------------
// Jikken - 3D Abstract High Performance Graphics API
// Copyright(c) 2017 Jeff Hutchinson
// Copyright(c) 2017 Tim Barnes
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-----------------------------------------------------------------------------

#ifndef _JIKKEN_GL_GLGRAPHICSDEVICE_HPP_
#define _JIKKEN_GL_GLGRAPHICSDEVICE_HPP_

#include "jikken/graphicsDevice.hpp"

namespace Jikken
{
	class GLGraphicsDevice : public GraphicsDevice
	{
		GLGraphicsDevice();
		virtual ~GLGraphicsDevice();

		virtual ShaderHandle createShader(const std::vector<ShaderDetails> &shaders) override;

		virtual BufferHandle createBuffer(BufferType type, BufferUsageHint hint, size_t dataSize, float *data) override;

		virtual LayoutHandle createVertexInputLayout(const std::vector<VertexInputLayout> &attributes) override;

		virtual VertexArrayHandle createVAO(LayoutHandle layout, BufferHandle vertexBuffer, BufferHandle indexBuffer = 0) override;

		virtual void bindConstantBuffer(ShaderHandle shader, BufferHandle cBuffer, int32_t index) override;

		virtual void deleteVertexInputLayout(LayoutHandle handle) override;

		virtual void deleteVAO(VertexArrayHandle handle) override;

		virtual void deleteBuffer(BufferHandle handle) override;

		virtual void deleteShader(ShaderHandle handle) override;

		virtual void submitCommandQueue() override;

	protected:
		void _processCmd(ICommand *cmd);
	};
}

#endif