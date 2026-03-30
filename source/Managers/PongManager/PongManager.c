#include <string.h>

#include <Printer.h>

#include "PongManager.h"

void PongManager::constructor(Stage stage)
{
	Base::constructor();

	this->leftScore = 0;
	this->rightScore = 0;

	PongManager::printScore(this);

	if (!isDeleted(stage)) 
	{
		Actor disk = Actor::safeCast(Stage::getChildByName(stage, (char*)DISK_NAME, false));

		if (!isDeleted(disk))
		{
			Actor::addEventListener(disk, ListenerObject::safeCast(this), kEventActorDeleted);
		}

		Stage::addActorLoadingListener(stage, ListenerObject::safeCast(this));
	}
}

void PongManager::destructor()
{
	Base::destructor();
}

void PongManager::printScore()
{
	Printer::int32(this->leftScore, 24 - 3, 0, NULL);
	Printer::int32(this->rightScore, 24 + 3, 0, NULL);
}

bool PongManager::onEvent(ListenerObject eventFirer, uint16 eventCode)
{
    switch(eventCode)
    {
        case kEventActorDeleted:
        {
            if(strcmp("Disk", Actor::getName(eventFirer)) == 0)
            {
                if(Actor::getPosition(eventFirer)->x > 0)
                {
                    ++this->leftScore;
                }
                else
                {
                    ++this->rightScore;
                }

                PongManager::printScore(this);
            }

			// Remove the listener as the actor is deleted
            return false;
        }

        case kEventActorCreated:
        {
            if(strcmp("Disk", Actor::getName(eventFirer)) == 0)
            {
                Actor::addEventListener(eventFirer, ListenerObject::safeCast(this), kEventActorDeleted);
            }

			// Maintain the listener so it fires again
            return true;
        }

		case kEventFontRewritten:
        {
            PongManager::printScore(this);
			
			// Maintain the listener
			return true;
		}
    }

    return Base::onEvent(this, eventFirer, eventCode);
}
