#version 430 core

in vec3 ex_normal;
in vec3 ex_fragPos;
in vec3 ex_lightVector;

struct Surface {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform Surface u_surface;
uniform vec3 u_lightColor;
uniform vec4 u_viewPos;

layout (location=0) out vec4 ex_fragColor;

void main(void) {
    // Ambient
    vec4 ambient = u_lightColor * u_surface.ambient;

    vec3 norm = normalize(ex_normal);

    // Diffuse calculation
    float diffuseCoef = max(dot(ex_lightVector, norm), 0.0f);
    vec4 diffuse = diffuseCoef * vec4(u_surface.diffuse,1.0);

    //Specular calculation
    vec3 viewDir = normalize(u_viewPos.xyz - ex_fragPos);
    vec3  halfVec = normalize(ex_lightVector + viewDir);
    float spec = pow(max(dot(norm, halfVec), 0.0) u_surface.shininess);
    vec4 specular = spec * vec4(u_surface.specular,1.0);

    if(dot(ex_lightVector, norm) < 0.0) {
        specular = vec4(0.0,0.0,0.0,1.0);
    } 

    // Light vector is normalized
    float lightDst = length(ex_lightVector);
    float lightAttenuation = 1/lightDst;
    vec4 res = lightAttenuation * diffuse * ambient * specular;
    ex_fragColor = res;
}