#version 110

struct Light
{
	vec4	type;		// тип источника, let's put attenuation coefficient in type.y, spotlight inner angle - in type.z, spotlight outer angle in type.w
	vec4	position;	// позиция источника (есть у Point и Spot)
	vec4	direction;	// направление света
	vec4	color;		// (цвет.r, цвет.g, цвет.b, интенсивность)
};

// Shader parameters
uniform mat4 matWorldNormal;
uniform mat4 matWorldT;
uniform vec4 materialColor;
uniform vec4 lightsCount;
uniform vec4 materialReflectiveness;
uniform Light lights[3];
uniform vec4 cameraPosition;

varying vec3 localPosition;
varying vec3 localNormal;


vec3 calcDiffuse(vec4 lightCol, vec3 lightDir, vec3 vertexNormal)
{
	float diffuse = clamp( dot(-lightDir, vertexNormal), 0.0, 1.0 );

	// Цвет = diffuse * (цвет источника) * (интенсивность источника)
	vec3 color = diffuse * lightCol.rgb * lightCol.a;

	return color;
}

float calcAttenuation(vec3 vertexPos, vec3 lightPos, float attenuationCoeff)
{
	return 1.0 / (attenuationCoeff * distance(vertexPos, lightPos) * distance(vertexPos, lightPos));
}



void main()
{
	vec3 col = vec3(0,0,0);

	// Переводим нормаль из локальной в глобальную систему координат
	vec3 vertexNormal = (vec4(localNormal, 0.0) * matWorldNormal).xyz;
	vertexNormal = normalize(vertexNormal);
	
	// Переводим позицию из локальной в глобальную систему координат
	vec3 vertexPos = (vec4(localPosition, 1.0) * matWorldT).xyz;
	
	for (int i = 0; i < 3; ++i)
	{
		// Выходим, как только закончились источники освещения
        if (float(i) >= lightsCount.x) 
        	break;
		
		float type = lights[i].type.x;
		float epsilon = 0.001;
		
		vec4 lightCol = lights[i].color;
		vec3 lightDir = vec3(0,0,0);
		vec3 specLDir = vec3(0,0,0);

		float attenuation = 1.0;
	
		// Directional light
        if (abs(type - 1.0) < epsilon)
		{
			lightDir = normalize(lights[i].direction.xyz).xyz;
			specLDir = lightDir;
		}
		// Point light
        else if (abs(type - 2.0) < epsilon)
		{
			lightDir = normalize(vertexPos - lights[i].position.xyz).xyz;

			attenuation = calcAttenuation(vertexPos, lights[i].position.xyz, lights[i].type.y);
			specLDir = lightDir;
		}
		// Spotlight
		else if (abs(type - 3.0) < epsilon) 
		{
			lightDir = lights[i].direction.xyz;
			float cosine_of_angle_to_spotlight = dot(normalize(lightDir), normalize(vertexPos - lights[i].position.xyz)); 
			float angle = acos(cosine_of_angle_to_spotlight);
			if (angle > lights[i].type.w) {
				attenuation = 0.0;
			}
			else if (angle > lights[i].type.y) {
				attenuation = calcAttenuation(vertexPos, lights[i].position.xyz, lights[i].type.y);
			}
			else attenuation = 1.0;
			specLDir = normalize(vertexPos - lights[i].position.xyz).xyz;
		}
		float specular = pow(dot(vertexNormal, normalize(normalize(-cameraPosition.xyz - vertexPos) + specLDir)), 
			materialReflectiveness.x);

		col += materialColor.rgb * calcDiffuse(lightCol, lightDir, vertexNormal) * attenuation * specular; 
	}
	
	gl_FragColor = vec4(col, 1.0);
    gl_FragColor.a = 1.0;
}
