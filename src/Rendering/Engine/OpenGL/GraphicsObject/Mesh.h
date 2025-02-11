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

#include "VertexArray.h"

namespace dyno
{
	// basic triangle mesh object
	class Mesh : public VertexArray
	{
		GL_OBJECT(Mesh)
	public:
		virtual void create() override;
		virtual void release() override;
		virtual void draw(int instance = 0);

	public:
		// static methods to create common mesh object
		static Mesh* Sphere(float radius = 1.f, int sectors = 16, int stacks = 8);
		static Mesh* ScreenQuad();
		static Mesh* Plane(float scale);

	private:
		Buffer	vbo;
		Buffer	ibo;
		int		count;
	};
}