#include "SmSdk/Creation/CreationManager.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

BodyStructure* CreationManager::_getBodyData(int id)
{
	auto iter = m_mapBodies.find(id);
	if (iter == m_mapBodies.end())
		return nullptr;

	return &iter->second;
}

JointStructure* CreationManager::_getJointData(int id)
{
	auto iter = m_mapJoints.find(id);
	if (iter == m_mapJoints.end())
		return nullptr;

	return &iter->second;
}

BodyStructure* CreationManager::GetBodyData(int id)
{
	CreationManager* pCreationManager = CreationManager::GetInstance();
	if (!pCreationManager)
		return nullptr;

	return pCreationManager->_getBodyData(id);
}

JointStructure* CreationManager::GetJointData(int id)
{
	CreationManager* pCreationManager = CreationManager::GetInstance();
	if (!pCreationManager)
		return nullptr;

	return pCreationManager->_getJointData(id);
}