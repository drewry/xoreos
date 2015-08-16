/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  Neverwinter Nights engine functions messing with creatures.
 */

#include "src/aurora/nwscript/functioncontext.h"

#include "src/engines/nwn/types.h"
#include "src/engines/nwn/objectcontainer.h"
#include "src/engines/nwn/object.h"
#include "src/engines/nwn/creature.h"

#include "src/engines/nwn/script/functions.h"

namespace Engines {

namespace NWN {

void Functions::getAbilityScore(Aurora::NWScript::FunctionContext &ctx) {
	// TODO: nBaseAbilityScore

	Creature *creature = NWN::ObjectContainer::toCreature(getParamObject(ctx, 0));
	Ability   ability  = (Ability) ctx.getParams()[1].getInt();

	ctx.getReturn() = creature ? (int32) creature->getAbility(ability) : 0;
}

void Functions::getIsDead(Aurora::NWScript::FunctionContext &ctx) {
	Creature *creature = NWN::ObjectContainer::toCreature(getParamObject(ctx, 0));

	ctx.getReturn() = creature ? (creature->getCurrentHP() <= 0) : false;
}

void Functions::getRacialType(Aurora::NWScript::FunctionContext &ctx) {
	Creature *creature = NWN::ObjectContainer::toCreature(getParamObject(ctx, 0));

	ctx.getReturn() = (int32) (creature ? creature->getRace() : kRaceInvalid);
}

void Functions::getLawChaosValue(Aurora::NWScript::FunctionContext &ctx) {
	Creature *creature = NWN::ObjectContainer::toCreature(getParamObject(ctx, 0));

	ctx.getReturn() = creature ? (int32) creature->getLawChaos() : -1;
}

void Functions::getGoodEvilValue(Aurora::NWScript::FunctionContext &ctx) {
	Creature *creature = NWN::ObjectContainer::toCreature(getParamObject(ctx, 0));

	ctx.getReturn() = creature ? (int32) creature->getGoodEvil() : -1;
}

void Functions::getAlignmentLawChaos(Aurora::NWScript::FunctionContext &ctx) {
	Creature *creature = NWN::ObjectContainer::toCreature(getParamObject(ctx, 0));

	ctx.getReturn() = creature ? (int32) NWN::getAlignmentLawChaos(creature->getLawChaos()) : -1;
}

void Functions::getAlignmentGoodEvil(Aurora::NWScript::FunctionContext &ctx) {
	Creature *creature = NWN::ObjectContainer::toCreature(getParamObject(ctx, 0));

	ctx.getReturn() = creature ? (int32) NWN::getAlignmentGoodEvil(creature->getGoodEvil()) : -1;
}

} // End of namespace NWN

} // End of namespace Engines
