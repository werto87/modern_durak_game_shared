#pragma once

#include <boost/algorithm/string.hpp>
#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/fusion/adapted/struct/define_struct.hpp>
#include <boost/fusion/algorithm/query/count.hpp>
#include <boost/fusion/functional.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/algorithm.hpp>
#include <boost/fusion/include/at.hpp>
#include <boost/fusion/include/count.hpp>
#include <boost/fusion/include/define_struct.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic_fwd.hpp>
#include <boost/hana/assert.hpp>
#include <boost/hana/at_key.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/find.hpp>
#include <boost/hana/for_each.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/map.hpp>
#include <boost/hana/optional.hpp>
#include <boost/hana/pair.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/range_c.hpp>
#include <cstddef>
#include <durak/card.hxx>
#include <durak/gameData.hxx>
#include <durak/gameOption.hxx>
#include <iostream>
#include <map>
#include <modern_durak_game_option/userDefinedGameOption.hxx>
#include <optional>
#include <sstream>
#include <string>
#include <variant>

typedef std::vector<std::pair<std::string, long long int> > UserTimeMilliseconds;
namespace shared_class
{
enum struct Move
{
  AttackAssistPass,
  AttackAssistDoneAddingCards,
  AddCards,
  Defend,
  TakeCards,
  AnswerDefendWantsToTakeCardsYes,
  AnswerDefendWantsToTakeCardsNo
};
}

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4003)
#endif
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakTimers, (UserTimeMilliseconds, runningTimeUserTimePointMilliseconds) (UserTimeMilliseconds, pausedTimeUserDurationMilliseconds))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttack, (std::vector<durak::Card>, cards))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttackSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttackError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefend, (durak::Card, cardToBeat) (durak::Card, card))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttackPass, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttackPassSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttackPassError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAssistPass, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAssistPassSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAssistPassError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendPass, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendPassSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendPassError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAskDefendWantToTakeCards, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAskDefendWantToTakeCardsAnswer, (bool, answer))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAskDefendWantToTakeCardsAnswerSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAskDefendWantToTakeCardsAnswerError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendWantsToTakeCardsFromTableDoYouWantToAddCards, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendWantsToTakeCardsFromTableDoYouWantToAddCardsAnswer, (bool, answer))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendWantsToTakeCardsFromTableDoneAddingCards, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendWantsToTakeCardsFromTableDoneAddingCardsSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendWantsToTakeCardsFromTableDoneAddingCardsError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakGameOverWon, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakGameOverLose, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakGameOverDraw, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakLeaveGame, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakLeaveGameError, (std::string, error))

BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAllowedMoves, (bool, hasToMove) (std::vector<shared_class::Move>, allowedMoves))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), UnhandledEventError, (std::string, unhandledEvent) (std::string, reason))

// MODERN DURAK TYPES //////////////////////////////////////////////////////////////////////////////////////////////

BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakNextMove, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakNextMoveError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakNextMoveSuccess, (shared_class::Move, nextMove) (std::optional<durak::Card>, card))

namespace shared_class
{
using PlayerNameAndCards = std::pair<std::string, std::vector<std::optional<durak::Card> > >;
}
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakWaitingForEndOfRoundAnimation, (bool, defendTakesCardsFromTable) (shared_class::PlayerNameAndCards, playerNameAndCardsToDraw))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDoneWithEndOfRoundAnimation, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CombinationSolved, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), GetCombinationSolved, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CombinationsSolved, (std::string, accountName) (size_t, combinationsSolved))

#ifdef _MSC_VER
#pragma warning(pop)
#endif