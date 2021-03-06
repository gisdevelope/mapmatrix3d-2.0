#pragma once
#include "BaseUserEvent.h"
#include "operationState.h"
#include "InterfaceUserEventCallBack.h"

class COsgMoveWholeSceneZEvent : public CBaseUserEvent
{
public:
	COsgMoveWholeSceneZEvent(osgViewer::Viewer *viewer, osg::Group *root, InterfaceSigEventCallBack* iSigEventCallBack) : CBaseUserEvent(viewer)
	{
		mViewer = viewer;
		mRoot = root;
		isActivated = false;
		this->iSigEventCallBack = iSigEventCallBack;
	}

	void UpdateActivatedStatus(std::vector<OperatingState> vecOpState);

protected:
	virtual bool handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa);

	void KeyPressAdjustWholeScene(double xDecimal, double yDecimal, double zDecimal, osg::ref_ptr<osg::Node> sceneNode);

protected:
	std::vector<osg::Vec3d> vecWorldCoord;

	osgViewer::Viewer *mViewer;
	osg::Group *mRoot;
	bool isActivated;

	InterfaceSigEventCallBack* iSigEventCallBack;

};