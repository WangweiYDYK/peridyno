/**
 * Copyright 2017-2021 Jian SHI
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "GraphicsObject.h"

namespace dyno
{
	class Framebuffer : public GraphicsObject
	{
		GL_OBJECT(Framebuffer)
	public:
		void create() override;
		void release() override;

		void bind(unsigned int target = 0x8CA9);	// default bind to GL_DRAW_FRAMEBUFFER
		void unbind();

		void clearColor(float r = 0.f, float g = 0.f, float b = 0.f, float a = 1.f);
		void clearDepth(float depth = 1.f);

		void setTexture2D(unsigned int attachment, unsigned int tex, int level = 0);

		void drawBuffers(int count, const unsigned int* buffers);
		
		int checkStatus();

	public:
		// current framebuffer binding
		static unsigned int current();
	};
}
