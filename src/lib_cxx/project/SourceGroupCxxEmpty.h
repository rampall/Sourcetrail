#ifndef SOURCE_GROUP_CXX_EMPTY_H
#define SOURCE_GROUP_CXX_EMPTY_H

#include <memory>
#include <set>

#include "project/SourceGroup.h"

class SourceGroupSettingsCxx;

class SourceGroupCxxEmpty: public SourceGroup
{
public:
	SourceGroupCxxEmpty(std::shared_ptr<SourceGroupSettingsCxx> settings);

	std::set<FilePath> filterToContainedFilePaths(const std::set<FilePath>& filePaths) const override;
	std::set<FilePath> getAllSourceFilePaths() const override;
	std::vector<std::shared_ptr<IndexerCommand>> getIndexerCommands(const std::set<FilePath>& filesToIndex) const override;

private:
	std::shared_ptr<SourceGroupSettings> getSourceGroupSettings() override;
	std::shared_ptr<const SourceGroupSettings> getSourceGroupSettings() const override;

	std::shared_ptr<SourceGroupSettingsCxx> m_settings;
};

#endif // SOURCE_GROUP_CXX_EMPTY_H
