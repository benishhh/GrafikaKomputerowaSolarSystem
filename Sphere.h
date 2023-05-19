#include "Mesh.h"

#define M_PI 3.1416

std::vector<Vertex> GenerateSphereVertices(float radius, int sectorCount, int stackCount) {
	std::vector<Vertex> vertices;

	float sectorStep = 2 * M_PI / sectorCount;
	float stackStep = M_PI / stackCount;

	for (int i = 0; i <= stackCount; ++i) {
		float stackAngle = M_PI / 2 - i * stackStep; // Rozpiêtoœæ od -90° do 90°
		float xy = radius * cosf(stackAngle);
		float z = radius * sinf(stackAngle);

		for (int j = 0; j <= sectorCount; ++j) {
			float sectorAngle = j * sectorStep; // Rozpiêtoœæ od 0° do 360°

			// Wyznaczanie pozycji wierzcho³ka na sferze
			float x = xy * cosf(sectorAngle);
			float y = xy * sinf(sectorAngle);

			// Tworzenie wierzcho³ka
			Vertex vertex;
			vertex.position = glm::vec3(x, y, z);
			vertex.normal = glm::normalize(vertex.position);
			vertex.color = glm::vec3((float)sin(sectorAngle), (float)cos(sectorAngle), (float)sin(sectorAngle) * 0.4);
			vertex.texUV = glm::vec2((float)j / sectorCount, (float)i / stackCount);


			vertices.push_back(vertex);
		}
	}

	return vertices;
}

std::vector<unsigned int> GenerateSphereIndices(int sectorCount, int stackCount) {
	std::vector<GLuint> indices;

	int numVertices = (sectorCount + 1) * (stackCount + 1);
	int numIndices = sectorCount * stackCount * 6;

	for (int i = 0; i < stackCount; ++i) {
		int k1 = i * (sectorCount + 1); // Pocz¹tek stosu
		int k2 = k1 + sectorCount + 1;	// Pocz¹tek kolejnego stosu

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2) {
			if (i != 0) {
				// Dolny trójk¹t
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			if (i != (stackCount - 1)) {
				// Górny trójk¹t
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}

	return indices;
}
