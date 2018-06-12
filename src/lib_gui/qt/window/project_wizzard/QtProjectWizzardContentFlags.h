#ifndef QT_PROJECT_WIZZARD_CONTENT_FLAGS_H
#define QT_PROJECT_WIZZARD_CONTENT_FLAGS_H

#include "qt/window/project_wizzard/QtProjectWizzardContent.h"

class QtStringListBox;
class SourceGroupSettingsCxx;

class QtProjectWizzardContentFlags
	: public QtProjectWizzardContent
{
	Q_OBJECT

public:
	QtProjectWizzardContentFlags(std::shared_ptr<SourceGroupSettingsCxx> settings, QtProjectWizzardWindow* window, bool indicateAsAdditional = false);

	// QtProjectWizzardContent implementation
	virtual void populate(QGridLayout* layout, int& row) override;

	virtual void load() override;
	virtual void save() override;
	virtual bool check() override;

private:
	std::shared_ptr<SourceGroupSettingsCxx> m_settings;
	const bool m_indicateAsAdditional;

	QtStringListBox* m_list;
};

#endif // QT_PROJECT_WIZZARD_CONTENT_FLAGS_H
