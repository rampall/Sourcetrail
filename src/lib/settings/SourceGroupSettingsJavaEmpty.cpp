#include "settings/SourceGroupSettingsJavaEmpty.h"

SourceGroupSettingsJavaEmpty::SourceGroupSettingsJavaEmpty(const std::string& id, const ProjectSettings* projectSettings)
	: SourceGroupSettingsJava(id, SOURCE_GROUP_JAVA_EMPTY, projectSettings)
{
}

void SourceGroupSettingsJavaEmpty::load(std::shared_ptr<const ConfigManager> config)
{
	SourceGroupSettings::load(config);

	const std::string key = s_keyPrefix + getId();

	SourceGroupSettingsWithSourcePaths::load(config, key);
	SourceGroupSettingsWithClasspath::load(config, key);
}

void SourceGroupSettingsJavaEmpty::save(std::shared_ptr<ConfigManager> config)
{
	SourceGroupSettings::save(config);

	const std::string key = s_keyPrefix + getId();

	SourceGroupSettingsWithSourcePaths::save(config, key);
	SourceGroupSettingsWithClasspath::save(config, key);
}

bool SourceGroupSettingsJavaEmpty::equals(std::shared_ptr<SourceGroupSettings> other) const
{
	std::shared_ptr<SourceGroupSettingsJavaEmpty> otherJava = std::dynamic_pointer_cast<SourceGroupSettingsJavaEmpty>(other);

	return (
		otherJava &&
		SourceGroupSettingsJava::equals(other) &&
		SourceGroupSettingsWithSourcePaths::equals(otherJava) &&
		SourceGroupSettingsWithClasspath::equals(otherJava)
	);
}

const ProjectSettings* SourceGroupSettingsJavaEmpty::getProjectSettings() const
{
	return m_projectSettings;
}
