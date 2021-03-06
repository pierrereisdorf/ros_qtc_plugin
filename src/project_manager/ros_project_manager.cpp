/**
 * @author Levi Armstrong
 * @date January 1, 2016
 *
 * @copyright Copyright (c) 2016, Southwest Research Institute
 *
 * @license Software License Agreement (Apache License)\n
 * \n
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at\n
 * \n
 * http://www.apache.org/licenses/LICENSE-2.0\n
 * \n
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "ros_project_manager.h"
#include "ros_project_constants.h"
#include "ros_project.h"

#include <coreplugin/icore.h>

#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/projectexplorerconstants.h>
#include <projectexplorer/session.h>

#include <extensionsystem/pluginmanager.h>

#include <QDebug>

namespace ROSProjectManager {
namespace Internal {

static ROSManager *m_instance = 0;

ROSManager::ROSManager()
{
  m_instance = this;
  m_terminalPane = new ROSTerminalPane();
  ExtensionSystem::PluginManager::addObject(m_terminalPane);
}

ROSManager::~ROSManager()
{
  m_instance = 0;
  ExtensionSystem::PluginManager::removeObject(m_terminalPane);
  delete m_terminalPane;
}

ROSManager *ROSManager::instance()
{
  return m_instance;
}

QTermWidget &ROSManager::startTerminal(int startnow, const QString name)
{
  return m_terminalPane->startTerminal(startnow, name);
}

} // namespace Internal
} // namespace ROSProjectManager
