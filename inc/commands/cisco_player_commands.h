#ifndef CISCO_VOLUMECOMMAND_H
#define CISCO_VOLUMECOMMAND_H

#include "commands/webdriver_command.h"
#include "webdriver_cisco_player_commands_interface.h"
#include "base/values.h"
#include "base/bind.h"
#include "commands/response.h"
#include "webdriver_error.h"
#include "webdriver_session.h"
#include "webdriver_view_executor.h"
#include "webdriver_util.h"

namespace base {
class DictionaryValue;
}

namespace webdriver {

class Response;

class CISCO_VolumeCommand : public ViewCommand
{
public:
    CISCO_VolumeCommand(const std::vector<std::string>& path_segments,
                        const base::DictionaryValue* parameters);
    virtual ~CISCO_VolumeCommand();

    virtual bool DoesGet() const OVERRIDE;
    virtual bool DoesPost() const OVERRIDE;
    virtual void ExecuteGet(Response* const response) OVERRIDE;
    virtual void ExecutePost(Response* const response) OVERRIDE;

private:
    DISALLOW_COPY_AND_ASSIGN(CISCO_VolumeCommand);
};

class CISCO_StateCommand : public ViewCommand
{
public:
    CISCO_StateCommand(const std::vector<std::string>& path_segments,
                        const base::DictionaryValue* parameters);
    virtual ~CISCO_StateCommand();

    virtual bool DoesGet() const OVERRIDE;
    virtual bool DoesPost() const OVERRIDE;
    virtual void ExecuteGet(Response* const response) OVERRIDE;
    virtual void ExecutePost(Response* const response) OVERRIDE;

private:
    DISALLOW_COPY_AND_ASSIGN(CISCO_StateCommand);
};

class CISCO_SeekCommand : public ViewCommand
{
public:
    CISCO_SeekCommand(const std::vector<std::string>& path_segments,
                        const base::DictionaryValue* parameters);
    virtual ~CISCO_SeekCommand();

    virtual bool DoesGet() const OVERRIDE;
    virtual bool DoesPost() const OVERRIDE;
    virtual void ExecuteGet(Response* const response) OVERRIDE;
    virtual void ExecutePost(Response* const response) OVERRIDE;

private:
    DISALLOW_COPY_AND_ASSIGN(CISCO_SeekCommand);
};

}

#endif // CISCO_VOLUMECOMMAND_H
