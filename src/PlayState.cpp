#include "PlayState.h"
#include <OgreTextureUnitState.h>

using namespace Ogre;

PlayState* PlayState::mPlayState;

void PlayState::enter() {
    mRoot             = Root::getSingletonPtr();
    mOverlayMgr       = OverlayManager::getSingletonPtr();
    mInputDevice      = InputManager::getSingletonPtr()->getKeyboard();
    mSceneMgr         = mRoot->getSceneManager( "ST_GENERIC" );
    mCamera           = mSceneMgr->createCamera( "PlayCamera" );
    mViewport         = mRoot->getAutoCreatedWindow()->addViewport( mCamera );

    mInfoOverlay      = mOverlayMgr->getByName( "Overlay/Info" );
    mPlayOverlay      = mOverlayMgr->getByName( "Overlay/PlayState" );
    mMouseOverlay     = mOverlayMgr->getByName( "Overlay/MousePointer" );

    mInfoInstruction  = mOverlayMgr->getOverlayElement( "Info/Instruction" );
    mInfoNotification = mOverlayMgr->getOverlayElement( "Info/Notification" );
    mMousePointer     = mOverlayMgr->getOverlayElement( "MousePointer/Pointer" );

    mInfoOverlay->show();
    mPlayOverlay->show();
    mMouseOverlay->show();

    mInfoInstruction->setCaption( "Press space for pause" );
}

void PlayState::exit() {
    mInfoOverlay->hide();
    mPlayOverlay->hide();
    mMouseOverlay->hide();

    mSceneMgr->clearScene();
    mSceneMgr->destroyAllCameras();
    mRoot->getAutoCreatedWindow()->removeAllViewports();
}

void PlayState::pause() {
    mInfoOverlay->hide();
    mPlayOverlay->hide();
    mMouseOverlay->hide();
}

void PlayState::resume() {
    mInfoOverlay->show();
    mPlayOverlay->show();
    mMouseOverlay->show();

    mInfoInstruction->setCaption( "Press space for pause" );
}

void PlayState::update( unsigned long lTimeElapsed ) {
    // Update wat je moet updaten
}

void PlayState::keyPressed( const OIS::KeyEvent &e ) {
}

void PlayState::keyReleased( const OIS::KeyEvent &e ) {
    if( e.key == OIS::KC_SPACE ) {
        this->pushState( PauseState::getSingletonPtr() );
    }
    else if( e.key == OIS::KC_ESCAPE ) {
        this->requestShutdown();
    }
}

void PlayState::mouseMoved( const OIS::MouseEvent &e ) {
    const OIS::MouseState &mouseState = e.state;
    //mMousePointer->setTop( mouseStat.abY );
    //mMousePointer->setLeft( mouseState.abX );
    mMousePointer->setTop( mouseState.Y.abs );//yys  mouseState.abY
    mMousePointer->setLeft( mouseState.X.abs );//yys mouseState.abX
}

void PlayState::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
}

void PlayState::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
}

PlayState* PlayState::getSingletonPtr() {
    if( !mPlayState ) {
        mPlayState = new PlayState();
    }

    return mPlayState;
}

