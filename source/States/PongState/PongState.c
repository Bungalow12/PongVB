/*
 * Pong
 *
 * © Jonathan Wills
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <string.h>

#include <Camera.h>
#include <CameraEffectManager.h>
#include <I18n.h>
#include <Languages.h>
#include <Messages.h>
#include <Printer.h>
#include <Singleton.h>
#include <VIPManager.h>
#include <VUEngine.h>

#include "PongState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern StageROMSpec PongStageSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::enter(void* owner __attribute__((unused)))
{
    Base::enter(this, owner);

    // Load the stage
    extern StageROMSpec PongStageSpec;
    PongState::configureStage(this, (StageSpec*)&PongStageSpec, NULL);

	// Create the Pong game controller
	// this->pongManager = new PongManager(this->stage);

	// Start clocks to start animations, physics, etc
    PongState::startClocks(this);

	// Enable user input
	KeypadManager::enable();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::suspend(void* owner)
{
	Base::suspend(this, owner);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::resume(void* owner)
{
	Base::resume(this, owner);

	// Enable user input
	KeypadManager::enable();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::processUserInput(const UserInput* userInput)
{
    if(userInput->holdKey != 0)
    {
        PongState::propagateMessage(this, kMessageKeypadHoldDown);
    }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::constructor()
{
	// Always explicitly call the base's constructor
	Base::constructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::destructor()
{
	// Always explicitly call the base's destructor
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
