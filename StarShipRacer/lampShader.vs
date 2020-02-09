#version 410 core
layout (location = 0) in vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec2 offsets[25];

void main()
{
    vec2 offset = offsets[gl_InstanceID];
    gl_Position = projection * view * model * vec4(position, 1.0f);
    //gl_Position = projection * view * model * vec4(position + offset,0.0f, 1.0f);
   
}
