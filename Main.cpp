#include "Sphere.h"

using namespace std;

const unsigned int width = 800;
const unsigned int height = 800;


int main() {
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "SolarSystemNPM"
	GLFWwindow* window = glfwCreateWindow(width, height, "SolarSystemNPM", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);


	// Texture data
	Texture texturesSun[]{
		Texture("slonce.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("slonce.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesMerkury[]{
		Texture("merkury.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("merkury.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	Texture texturesWenus[]{
		Texture("wenus.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("wenus.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesZiemia[]{
		Texture("ziemia.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("ziemia.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesMars[]{
		Texture("mars.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("mars.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesJowisz[]{
		Texture("jowisz.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("jowisz.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesSaturn[]{
		Texture("saturn.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("saturn.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesUran[]{
		Texture("uran.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("uran.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesNeptun[]{
		Texture("neptun.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("neptun.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};


	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);



	float skala = 1.0 / 10000.0 / 2.0; // jedna dziesiêciotysiêczna przez 2  [ km ]
	float skala_odl = 1.0 / 1000000.0 * 4 / 5;
	float kat_rotacji = 90.0f;

	// S£OÑCE
	Shader sunShader("default.vert", "sundefault.frag");
	std::vector<Vertex> sunVertices = GenerateSphereVertices(696350*skala, 50, 50); // 6.69 to œrednica
	std::vector<GLuint> sunIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textSun(texturesSun, texturesSun + sizeof(texturesSun) / sizeof(Texture));
	Mesh sun(sunVertices, sunIndices, textSun);
	glm::vec3 sunPos = glm::vec3(0.0f, 0.0f, 0.0f); // gdzie siê znajduje na scenie

	// MERKURY
	Shader merkuryShader("default.vert", "default.frag");
	std::vector<Vertex> merkuryVertices = GenerateSphereVertices(2438*skala, 50, 50);
	std::vector<GLuint> merkuryIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> texMerkury(texturesMerkury, texturesMerkury + sizeof(texturesMerkury) / sizeof(Texture));
	Mesh merkury(merkuryVertices, merkuryIndices, texMerkury);
	glm::vec3 merkuryPos = glm::vec3(57740000.0  * skala_odl, 0.0f, 0.0f); // gdzie siê znajduje na scenie

	// WENUS
	Shader wenusShader("default.vert", "default.frag");
	std::vector<Vertex> wenusVertices = GenerateSphereVertices(6052*skala, 50, 50);
	std::vector<GLuint> wenusIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textWenus(texturesWenus, texturesWenus + sizeof(texturesWenus) / sizeof(Texture));
	Mesh wenus(wenusVertices, wenusIndices, textWenus);
	glm::vec3 wenusPos = glm::vec3(108141000.0 * 0.6 * skala_odl, 0.0f, 0.0f); // gdzie siê znajduje na scenie

	// Ziemia
	Shader ziemiaShader("default.vert", "default.frag");
	std::vector<Vertex> ziemiaVertices = GenerateSphereVertices(6378.0 * skala, 50, 50);
	std::vector<GLuint> ziemiaIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textZiemia(texturesZiemia, texturesZiemia + sizeof(texturesZiemia) / sizeof(Texture));
	Mesh ziemia(ziemiaVertices, ziemiaIndices, textZiemia);
	glm::vec3 ziemiaPos = glm::vec3(149504000 * 0.5 *skala_odl, 0.0f, 0.0f); // gdzie siê znajduje na scenie

	// Mars
	Shader marsShader("default.vert", "default.frag");
	std::vector<Vertex> marsVertices = GenerateSphereVertices(3430.0 * skala, 50, 50);
	std::vector<GLuint> marsIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textMars(texturesMars, texturesMars + sizeof(texturesMars) / sizeof(Texture));
	Mesh mars(marsVertices, marsIndices, textMars);
	glm::vec3 marsPos = glm::vec3(227789000.0 * 0.4 * skala_odl , 0.0f, 0.0f); // gdzie siê znajduje na scenie

	// jowisz
	Shader jowiszShader("default.vert", "default.frag");
	std::vector<Vertex> jowiszVertices = GenerateSphereVertices(71820.0 * skala, 50, 50);
	std::vector<GLuint> jowiszIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textJowisz(texturesJowisz, texturesJowisz + sizeof(texturesJowisz) / sizeof(Texture));
	Mesh jowisz(jowiszVertices, jowiszIndices, textJowisz);
	glm::vec3 jowiszPos = glm::vec3(777840000.0 * 0.25 * skala_odl, 0.0f, 0.0f); // gdzie siê znajduje na scenie

	// saturn
	Shader saturnShader("default.vert", "default.frag");
	std::vector<Vertex> saturnVertices = GenerateSphereVertices(60285.0 * skala, 50, 50);
	std::vector<GLuint> saturnIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textSaturn(texturesSaturn, texturesSaturn + sizeof(texturesSaturn) / sizeof(Texture));
	Mesh saturn(saturnVertices, saturnIndices, textSaturn);
	glm::vec3 saturnPos = glm::vec3(1426100000.0 * 0.2 * skala_odl, 0.0f, 0.0f); // gdzie siê znajduje na scenie

	// uran
	Shader uranShader("default.vert", "default.frag");
	std::vector<Vertex> uranVertices = GenerateSphereVertices(28535.0 * skala, 50, 50);
	std::vector<GLuint> uranIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textUran(texturesUran, texturesUran + sizeof(texturesUran) / sizeof(Texture));
	Mesh uran(uranVertices, uranIndices, textUran);
	glm::vec3 uranPos = glm::vec3(2867830000.0 * 0.12 * skala_odl, 0.0f, 0.0f); // gdzie siê znajduje na scenie

	// neptun
	Shader neptunShader("default.vert", "default.frag");
	neptunShader.Activate();
	std::vector<Vertex> neptunVertices = GenerateSphereVertices(24835 * skala, 50, 50);
	std::vector<GLuint> neptunIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textNeptun(texturesNeptun, texturesNeptun + sizeof(texturesNeptun) / sizeof(Texture));
	Mesh neptun(neptunVertices, neptunIndices, textNeptun);
	glm::vec3 neptunPos = glm::vec3(4493650000.0 * 0.09 * skala_odl, 0.0f, 0.0f); // gdzie siê znajduje na scenie


	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	float rotation = 0.0f;
	double prevTime = glfwGetTime();
	float speed_of_rotation = 0.5f;


	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		// Specify the color of the background
		glClearColor(0.0f, 0.0f, 0.01f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 800.0f);

		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1.0 / 60.0) {
			rotation += 360.0f / 350.0f * speed_of_rotation;
			prevTime = crntTime;
		}

		// ROTACJE I OBROTY PLANET

		// rotacja o 90* dla ka¿dej planej, ¿eby tekstury zgadza³y siê ze stanem faktycznym
		glm::mat4 rotacja90stopni = glm::rotate(glm::mat4(1.0f), glm::radians(kat_rotacji), glm::vec3(1.0f, 0.0f, 0.0f));

		sunShader.Activate();
		glm::mat4 sunRotation = glm::rotate(glm::mat4(1.0f), glm::radians(rotation / 10.0f), glm::vec3(0.0f, 1.0f, 1.0f));	
		glm::mat4 sunModel = sunRotation * glm::translate(glm::mat4(1.0f), sunPos);
		glUniformMatrix4fv(glGetUniformLocation(sunShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(sunModel));
		glUniform4f(glGetUniformLocation(sunShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(sunShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		merkuryShader.Activate();
		glm::mat4 merkuryRotation = glm::rotate(glm::mat4(1.0f),glm::radians(rotation * 1.2f), glm::vec3(0.0f, 1.0f, .0f));
		glm::mat4 merkuryModel = merkuryRotation * rotacja90stopni * glm::translate(glm::mat4(1.0f), merkuryPos);
		glUniformMatrix4fv(glGetUniformLocation(merkuryShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(merkuryModel));
		glUniform4f(glGetUniformLocation(merkuryShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(merkuryShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		wenusShader.Activate();
		glm::mat4 wenusRotation = glm::rotate(glm::mat4(1.0f), glm::radians(rotation * 1.1f), glm::vec3(0.0f, 1.0f, .0f));
		glm::mat4 wenusModel = wenusRotation * rotacja90stopni * glm::translate(glm::mat4(1.0f), wenusPos);
		glUniformMatrix4fv(glGetUniformLocation(wenusShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(wenusModel));
		glUniform4f(glGetUniformLocation(wenusShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(wenusShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		ziemiaShader.Activate();
		glm::mat4 ziemiaRotation = glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0.0f, 1.0f, .0f));
		glm::mat4 ziemiaModel = ziemiaRotation * rotacja90stopni * glm::translate(glm::mat4(1.0f), ziemiaPos);
		glUniformMatrix4fv(glGetUniformLocation(ziemiaShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(ziemiaModel));
		glUniform4f(glGetUniformLocation(ziemiaShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(ziemiaShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		marsShader.Activate();
		glm::mat4 marsRotation = glm::rotate(glm::mat4(1.0f), glm::radians(rotation / 2.0f), glm::vec3(0.0f, 1.0f, .0f));
		glm::mat4 marsModel = marsRotation * rotacja90stopni * glm::translate(glm::mat4(1.0f), marsPos);
		glUniformMatrix4fv(glGetUniformLocation(marsShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(marsModel));
		glUniform4f(glGetUniformLocation(marsShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(marsShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		jowiszShader.Activate();
		glm::mat4 jowiszRotation = glm::rotate(glm::mat4(1.0f), glm::radians(rotation / 11.6f), glm::vec3(0.0f, 1.0f, .0f));
		glm::mat4 jowiszModel = jowiszRotation * rotacja90stopni * glm::translate(glm::mat4(1.0f), jowiszPos);
		glUniformMatrix4fv(glGetUniformLocation(jowiszShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(jowiszModel));
		glUniform4f(glGetUniformLocation(jowiszShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(jowiszShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		saturnShader.Activate();
		glm::mat4 saturnRotation = glm::rotate(glm::mat4(1.0f), glm::radians(rotation / 29.0f), glm::vec3(0.0f, 1.0f, .0f));
		glm::mat4 saturnModel = saturnRotation * rotacja90stopni * glm::translate(glm::mat4(1.0f), saturnPos);
		glUniformMatrix4fv(glGetUniformLocation(saturnShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(saturnModel));
		glUniform4f(glGetUniformLocation(saturnShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(saturnShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		uranShader.Activate();
		glm::mat4 uranRotation = glm::rotate(glm::mat4(1.0f), glm::radians(rotation / 84.02f), glm::vec3(0.0f, 1.0f, .0f));
		glm::mat4 uranModel = uranRotation * rotacja90stopni * glm::translate(glm::mat4(1.0f), uranPos);
		glUniformMatrix4fv(glGetUniformLocation(uranShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(uranModel));
		glUniform4f(glGetUniformLocation(uranShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(uranShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		neptunShader.Activate();
		glm::mat4 neptunRotation = glm::rotate(glm::mat4(1.0f), glm::radians(rotation / 164.8f), glm::vec3(0.0f, 1.0f, .0f));
		glm::mat4 neptunModel = neptunRotation * rotacja90stopni * glm::translate(glm::mat4(1.0f), neptunPos);
		glUniformMatrix4fv(glGetUniformLocation(neptunShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(neptunModel));
		glUniform4f(glGetUniformLocation(neptunShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(neptunShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		// renderowanie ka¿dej z planet po naniesieniu ich odpowiedniego po³o¿enia na scenie
		sun.Draw(sunShader, camera);
		merkury.Draw(merkuryShader, camera);
		wenus.Draw(wenusShader, camera);
		ziemia.Draw(ziemiaShader, camera);
		mars.Draw(marsShader, camera);
		jowisz.Draw(jowiszShader, camera);
		saturn.Draw(saturnShader, camera);
		uran.Draw(uranShader, camera);
		neptun.Draw(neptunShader, camera);

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}


	merkuryShader.Delete();
	wenusShader.Delete();
	ziemiaShader.Delete();
	marsShader.Delete();
	jowiszShader.Delete();
	saturnShader.Delete();
	uranShader.Delete();
	neptunShader.Delete();

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}