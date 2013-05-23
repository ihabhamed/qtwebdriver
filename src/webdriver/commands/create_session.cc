// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "commands/create_session.h"

#include <string>

#include "base/file_path.h"
#include "base/scoped_temp_dir.h"
#include "base/values.h"
#include "commands/response.h"
#include "webdriver_error.h"
#include "webdriver_session.h"
#include "webdriver_session_manager.h"

namespace webdriver {

CreateSession::CreateSession(const std::vector<std::string>& path_segments,
                             const DictionaryValue* const parameters)
    : Command(path_segments, parameters) {}

CreateSession::~CreateSession() {}

bool CreateSession::DoesPost() { return true; }

void CreateSession::ExecutePost(Response* const response) {
    const DictionaryValue* dict;
    if (!GetDictionaryParameter("desiredCapabilities", &dict)) {
        response->SetError(new Error(
            kBadRequest, "Missing or invalid 'desiredCapabilities'"));
        return;
    }

    if (SessionManager::GetInstance()->GetSessions().size()  > 0) {
        response->SetError(new Error(kUnknownError, "Cannot start session. WD support only one session at the moment"));
        return;
    }

    // Session manages its own liftime, so do not call delete.
    Session* session = new Session();
    Error* error = session->Init(dict);
    if (error) {
        response->SetError(error);
        return;
    }

    // Redirect to a relative URI. Although prohibited by the HTTP standard,
    // this is what the IEDriver does. Finding the actual IP address is
    // difficult, and returning the hostname causes perf problems with the python
    // bindings on Windows.
    std::ostringstream stream;
    stream << SessionManager::GetInstance()->url_base() << "/session/"
            << session->id();
    response->SetStatus(kSeeOther);
    response->SetValue(Value::CreateStringValue(stream.str()));
}

}  // namespace webdriver
