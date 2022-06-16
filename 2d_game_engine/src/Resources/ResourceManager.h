#pragma once

#include <string>
#include <memory>
#include <map>

namespace Renderer
{
	class ShaderProgram;
}


class ResouceManager 
{
public:
	ResouceManager(const std::string& executablePath);
	~ResouceManager() = default;

	ResouceManager(const ResouceManager&) = delete;
	ResouceManager& operator=(const ResouceManager&) = delete;
	ResouceManager& operator=(ResouceManager&&) = delete;

	std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);
	std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& shaderName);

private:
	std::string getFileString(const std::string& relativeFilePath) const;

	typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramsMap;
	ShaderProgramsMap m_shaderProgram;

	std::string m_path;

};