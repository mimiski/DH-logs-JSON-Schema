# GENERATED USING https://app.quicktype.io/#l=python

# This code parses date/times, so please
#
#     pip install python-dateutil
#
# To use this code, make sure you
#
#     import json
#
# and then, to convert JSON from a string, do
#
#     result = coordinate_from_dict(json.loads(json_string))

from dataclasses import dataclass
from typing import List, Any, Optional, TypeVar, Callable, Type, cast
from datetime import datetime
from enum import Enum
import dateutil.parser


T = TypeVar("T")
EnumT = TypeVar("EnumT", bound=Enum)


def from_list(f: Callable[[Any], T], x: Any) -> List[T]:
    assert isinstance(x, list)
    return [f(y) for y in x]


def from_float(x: Any) -> float:
    assert isinstance(x, (float, int)) and not isinstance(x, bool)
    return float(x)


def to_float(x: Any) -> float:
    assert isinstance(x, float)
    return x


def from_str(x: Any) -> str:
    assert isinstance(x, str)
    return x


def from_int(x: Any) -> int:
    assert isinstance(x, int) and not isinstance(x, bool)
    return x


def to_class(c: Type[T], x: Any) -> dict:
    assert isinstance(x, c)
    return cast(Any, x).to_dict()


def from_datetime(x: Any) -> datetime:
    return dateutil.parser.parse(x)


def from_none(x: Any) -> Any:
    assert x is None
    return x


def from_union(fs, x):
    for f in fs:
        try:
            return f(x)
        except:
            pass
    assert False


def from_bool(x: Any) -> bool:
    assert isinstance(x, bool)
    return x


def to_enum(c: Type[EnumT], x: Any) -> EnumT:
    assert isinstance(x, c)
    return x.value


@dataclass
class Bounds:
    ne: List[float]
    sw: List[float]

    @staticmethod
    def from_dict(obj: Any) -> 'Bounds':
        assert isinstance(obj, dict)
        ne = from_list(from_float, obj.get("ne"))
        sw = from_list(from_float, obj.get("sw"))
        return Bounds(ne, sw)

    def to_dict(self) -> dict:
        result: dict = {}
        result["ne"] = from_list(to_float, self.ne)
        result["sw"] = from_list(to_float, self.sw)
        return result


@dataclass
class Map:
    bounds: Bounds
    name: str
    offset: int

    @staticmethod
    def from_dict(obj: Any) -> 'Map':
        assert isinstance(obj, dict)
        bounds = Bounds.from_dict(obj.get("bounds"))
        name = from_str(obj.get("name"))
        offset = from_int(obj.get("offset"))
        return Map(bounds, name, offset)

    def to_dict(self) -> dict:
        result: dict = {}
        result["bounds"] = to_class(Bounds, self.bounds)
        result["name"] = from_str(self.name)
        result["offset"] = from_int(self.offset)
        return result


@dataclass
class Session:
    ended_at: datetime
    ip: str
    started_at: datetime

    @staticmethod
    def from_dict(obj: Any) -> 'Session':
        assert isinstance(obj, dict)
        ended_at = from_datetime(obj.get("ended_at"))
        ip = from_str(obj.get("ip"))
        started_at = from_datetime(obj.get("started_at"))
        return Session(ended_at, ip, started_at)

    def to_dict(self) -> dict:
        result: dict = {}
        result["ended_at"] = self.ended_at.isoformat()
        result["ip"] = from_str(self.ip)
        result["started_at"] = self.started_at.isoformat()
        return result


@dataclass
class Player:
    id: str
    names: List[str]
    sessions: List[Session]

    @staticmethod
    def from_dict(obj: Any) -> 'Player':
        assert isinstance(obj, dict)
        id = from_str(obj.get("id"))
        names = from_list(from_str, obj.get("names"))
        sessions = from_list(Session.from_dict, obj.get("sessions"))
        return Player(id, names, sessions)

    def to_dict(self) -> dict:
        result: dict = {}
        result["id"] = from_str(self.id)
        result["names"] = from_list(from_str, self.names)
        result["sessions"] = from_list(lambda x: to_class(Session, x), self.sessions)
        return result


@dataclass
class Capture:
    objective_id: int
    player_ids: List[str]
    round_time: int
    team: int

    @staticmethod
    def from_dict(obj: Any) -> 'Capture':
        assert isinstance(obj, dict)
        objective_id = from_int(obj.get("objective_id"))
        player_ids = from_list(from_str, obj.get("player_ids"))
        round_time = from_int(obj.get("round_time"))
        team = from_int(obj.get("team"))
        return Capture(objective_id, player_ids, round_time, team)

    def to_dict(self) -> dict:
        result: dict = {}
        result["objective_id"] = from_int(self.objective_id)
        result["player_ids"] = from_list(from_str, self.player_ids)
        result["round_time"] = from_int(self.round_time)
        result["team"] = from_int(self.team)
        return result


@dataclass
class Construction:
    construction_class: str
    location: List[float]
    player_id: str
    round_time: int
    team: int

    @staticmethod
    def from_dict(obj: Any) -> 'Construction':
        assert isinstance(obj, dict)
        construction_class = from_str(obj.get("class"))
        location = from_list(from_float, obj.get("location"))
        player_id = from_str(obj.get("player_id"))
        round_time = from_int(obj.get("round_time"))
        team = from_int(obj.get("team"))
        return Construction(construction_class, location, player_id, round_time, team)

    def to_dict(self) -> dict:
        result: dict = {}
        result["class"] = from_str(self.construction_class)
        result["location"] = from_list(to_float, self.location)
        result["player_id"] = from_str(self.player_id)
        result["round_time"] = from_int(self.round_time)
        result["team"] = from_int(self.team)
        return result


@dataclass
class Team:
    munitions: float
    objectives_owned: int
    reinforcements: int
    size: int
    team_index: int

    @staticmethod
    def from_dict(obj: Any) -> 'Team':
        assert isinstance(obj, dict)
        munitions = from_float(obj.get("munitions"))
        objectives_owned = from_int(obj.get("objectives_owned"))
        reinforcements = from_int(obj.get("reinforcements"))
        size = from_int(obj.get("size"))
        team_index = from_int(obj.get("team_index"))
        return Team(munitions, objectives_owned, reinforcements, size, team_index)

    def to_dict(self) -> dict:
        result: dict = {}
        result["munitions"] = to_float(self.munitions)
        result["objectives_owned"] = from_int(self.objectives_owned)
        result["reinforcements"] = from_int(self.reinforcements)
        result["size"] = from_int(self.size)
        result["team_index"] = from_int(self.team_index)
        return result


@dataclass
class RoundState:
    round_time: int
    teams: List[Team]

    @staticmethod
    def from_dict(obj: Any) -> 'RoundState':
        assert isinstance(obj, dict)
        round_time = from_int(obj.get("round_time"))
        teams = from_list(Team.from_dict, obj.get("teams"))
        return RoundState(round_time, teams)

    def to_dict(self) -> dict:
        result: dict = {}
        result["round_time"] = from_int(self.round_time)
        result["teams"] = from_list(lambda x: to_class(Team, x), self.teams)
        return result


@dataclass
class Vote:
    option_id: int
    voter_ids: List[str]

    @staticmethod
    def from_dict(obj: Any) -> 'Vote':
        assert isinstance(obj, dict)
        option_id = from_int(obj.get("option_id"))
        voter_ids = from_list(from_str, obj.get("voter_ids"))
        return Vote(option_id, voter_ids)

    def to_dict(self) -> dict:
        result: dict = {}
        result["option_id"] = from_int(self.option_id)
        result["voter_ids"] = from_list(from_str, self.voter_ids)
        return result


@dataclass
class Data:
    ended_at: datetime
    nominator_ids: List[str]
    result_id: int
    round_state: RoundState
    started_at: datetime
    team_index: int
    vote_type: str
    votes: List[Vote]

    @staticmethod
    def from_dict(obj: Any) -> 'Data':
        assert isinstance(obj, dict)
        ended_at = from_datetime(obj.get("ended_at"))
        nominator_ids = from_list(from_str, obj.get("nominator_ids"))
        result_id = from_int(obj.get("result_id"))
        round_state = RoundState.from_dict(obj.get("round_state"))
        started_at = from_datetime(obj.get("started_at"))
        team_index = from_int(obj.get("team_index"))
        vote_type = from_str(obj.get("vote_type"))
        votes = from_list(Vote.from_dict, obj.get("votes"))
        return Data(ended_at, nominator_ids, result_id, round_state, started_at, team_index, vote_type, votes)

    def to_dict(self) -> dict:
        result: dict = {}
        result["ended_at"] = self.ended_at.isoformat()
        result["nominator_ids"] = from_list(from_str, self.nominator_ids)
        result["result_id"] = from_int(self.result_id)
        result["round_state"] = to_class(RoundState, self.round_state)
        result["started_at"] = self.started_at.isoformat()
        result["team_index"] = from_int(self.team_index)
        result["vote_type"] = from_str(self.vote_type)
        result["votes"] = from_list(lambda x: to_class(Vote, x), self.votes)
        return result


@dataclass
class Event:
    data: Data
    type: str

    @staticmethod
    def from_dict(obj: Any) -> 'Event':
        assert isinstance(obj, dict)
        data = Data.from_dict(obj.get("data"))
        type = from_str(obj.get("type"))
        return Event(data, type)

    def to_dict(self) -> dict:
        result: dict = {}
        result["data"] = to_class(Data, self.data)
        result["type"] = from_str(self.type)
        return result


@dataclass
class Killer:
    id: str
    location: List[int]
    pawn: str
    team: int
    vehicle: Optional[str] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Killer':
        assert isinstance(obj, dict)
        id = from_str(obj.get("id"))
        location = from_list(from_int, obj.get("location"))
        pawn = from_str(obj.get("pawn"))
        team = from_int(obj.get("team"))
        vehicle = from_union([from_none, from_str], obj.get("vehicle"))
        return Killer(id, location, pawn, team, vehicle)

    def to_dict(self) -> dict:
        result: dict = {}
        result["id"] = from_str(self.id)
        result["location"] = from_list(from_int, self.location)
        result["pawn"] = from_str(self.pawn)
        result["team"] = from_int(self.team)
        result["vehicle"] = from_union([from_none, from_str], self.vehicle)
        return result


@dataclass
class Frag:
    damage_type: str
    hit_index: int
    killer: Killer
    time: int
    victim: Killer

    @staticmethod
    def from_dict(obj: Any) -> 'Frag':
        assert isinstance(obj, dict)
        damage_type = from_str(obj.get("damage_type"))
        hit_index = from_int(obj.get("hit_index"))
        killer = Killer.from_dict(obj.get("killer"))
        time = from_int(obj.get("time"))
        victim = Killer.from_dict(obj.get("victim"))
        return Frag(damage_type, hit_index, killer, time, victim)

    def to_dict(self) -> dict:
        result: dict = {}
        result["damage_type"] = from_str(self.damage_type)
        result["hit_index"] = from_int(self.hit_index)
        result["killer"] = to_class(Killer, self.killer)
        result["time"] = from_int(self.time)
        result["victim"] = to_class(Killer, self.victim)
        return result


class DestroyedReason(Enum):
    DAMAGED = "damaged"
    DELETED = "deleted"
    ENCROACHED = "encroached"
    EXHAUSTED = "exhausted"
    OVERRUN = "overrun"
    REPLACED = "replaced"
    SPAWN_KILL = "spawn_kill"


@dataclass
class RallyPoint:
    created_at: datetime
    establisher_count: int
    is_established: bool
    location: List[float]
    player_id: str
    spawn_count: int
    squad_index: int
    team_index: int
    destroyed_at: Optional[datetime] = None
    destroyed_reason: Optional[DestroyedReason] = None

    @staticmethod
    def from_dict(obj: Any) -> 'RallyPoint':
        assert isinstance(obj, dict)
        created_at = from_datetime(obj.get("created_at"))
        establisher_count = from_int(obj.get("establisher_count"))
        is_established = from_bool(obj.get("is_established"))
        location = from_list(from_float, obj.get("location"))
        player_id = from_str(obj.get("player_id"))
        spawn_count = from_int(obj.get("spawn_count"))
        squad_index = from_int(obj.get("squad_index"))
        team_index = from_int(obj.get("team_index"))
        destroyed_at = from_union([from_none, from_datetime], obj.get("destroyed_at"))
        destroyed_reason = from_union([from_none, DestroyedReason], obj.get("destroyed_reason"))
        return RallyPoint(created_at, establisher_count, is_established, location, player_id, spawn_count, squad_index, team_index, destroyed_at, destroyed_reason)

    def to_dict(self) -> dict:
        result: dict = {}
        result["created_at"] = self.created_at.isoformat()
        result["establisher_count"] = from_int(self.establisher_count)
        result["is_established"] = from_bool(self.is_established)
        result["location"] = from_list(to_float, self.location)
        result["player_id"] = from_str(self.player_id)
        result["spawn_count"] = from_int(self.spawn_count)
        result["squad_index"] = from_int(self.squad_index)
        result["team_index"] = from_int(self.team_index)
        result["destroyed_at"] = from_union([from_none, lambda x: x.isoformat()], self.destroyed_at)
        result["destroyed_reason"] = from_union([from_none, lambda x: to_enum(DestroyedReason, x)], self.destroyed_reason)
        return result


@dataclass
class DestroyedVehicle:
    location: List[int]
    team: int
    vehicle: str

    @staticmethod
    def from_dict(obj: Any) -> 'DestroyedVehicle':
        assert isinstance(obj, dict)
        location = from_list(from_int, obj.get("location"))
        team = from_int(obj.get("team"))
        vehicle = from_str(obj.get("vehicle"))
        return DestroyedVehicle(location, team, vehicle)

    def to_dict(self) -> dict:
        result: dict = {}
        result["location"] = from_list(from_int, self.location)
        result["team"] = from_int(self.team)
        result["vehicle"] = from_str(self.vehicle)
        return result


@dataclass
class VehicleFrag:
    damage_type: str
    destroyed_vehicle: DestroyedVehicle
    killer: Killer
    time: int

    @staticmethod
    def from_dict(obj: Any) -> 'VehicleFrag':
        assert isinstance(obj, dict)
        damage_type = from_str(obj.get("damage_type"))
        destroyed_vehicle = DestroyedVehicle.from_dict(obj.get("destroyed_vehicle"))
        killer = Killer.from_dict(obj.get("killer"))
        time = from_int(obj.get("time"))
        return VehicleFrag(damage_type, destroyed_vehicle, killer, time)

    def to_dict(self) -> dict:
        result: dict = {}
        result["damage_type"] = from_str(self.damage_type)
        result["destroyed_vehicle"] = to_class(DestroyedVehicle, self.destroyed_vehicle)
        result["killer"] = to_class(Killer, self.killer)
        result["time"] = from_int(self.time)
        return result


@dataclass
class Round:
    captures: List[Capture]
    constructions: List[Construction]
    ended_at: datetime
    events: List[Event]
    frags: List[Frag]
    rally_points: List[RallyPoint]
    started_at: datetime
    vehicle_frags: List[VehicleFrag]
    winner: int

    @staticmethod
    def from_dict(obj: Any) -> 'Round':
        assert isinstance(obj, dict)
        captures = from_list(Capture.from_dict, obj.get("captures"))
        constructions = from_list(Construction.from_dict, obj.get("constructions"))
        ended_at = from_datetime(obj.get("ended_at"))
        events = from_list(Event.from_dict, obj.get("events"))
        frags = from_list(Frag.from_dict, obj.get("frags"))
        rally_points = from_list(RallyPoint.from_dict, obj.get("rally_points"))
        started_at = from_datetime(obj.get("started_at"))
        vehicle_frags = from_list(VehicleFrag.from_dict, obj.get("vehicle_frags"))
        winner = from_int(obj.get("winner"))
        return Round(captures, constructions, ended_at, events, frags, rally_points, started_at, vehicle_frags, winner)

    def to_dict(self) -> dict:
        result: dict = {}
        result["captures"] = from_list(lambda x: to_class(Capture, x), self.captures)
        result["constructions"] = from_list(lambda x: to_class(Construction, x), self.constructions)
        result["ended_at"] = self.ended_at.isoformat()
        result["events"] = from_list(lambda x: to_class(Event, x), self.events)
        result["frags"] = from_list(lambda x: to_class(Frag, x), self.frags)
        result["rally_points"] = from_list(lambda x: to_class(RallyPoint, x), self.rally_points)
        result["started_at"] = self.started_at.isoformat()
        result["vehicle_frags"] = from_list(lambda x: to_class(VehicleFrag, x), self.vehicle_frags)
        result["winner"] = from_int(self.winner)
        return result


@dataclass
class Server:
    name: str

    @staticmethod
    def from_dict(obj: Any) -> 'Server':
        assert isinstance(obj, dict)
        name = from_str(obj.get("name"))
        return Server(name)

    def to_dict(self) -> dict:
        result: dict = {}
        result["name"] = from_str(self.name)
        return result


class TypeEnum(Enum):
    COMMAND_SAY = "CommandSay"
    SAY = "Say"
    SQUAD_SAY = "SquadSay"
    TEAM_SAY = "TeamSay"
    VEHICLE_SAY = "VehicleSay"


@dataclass
class TextMessage:
    message: str
    sender: str
    sent_at: datetime
    squad_index: int
    team_index: int
    type: TypeEnum

    @staticmethod
    def from_dict(obj: Any) -> 'TextMessage':
        assert isinstance(obj, dict)
        message = from_str(obj.get("message"))
        sender = from_str(obj.get("sender"))
        sent_at = from_datetime(obj.get("sent_at"))
        squad_index = from_int(obj.get("squad_index"))
        team_index = from_int(obj.get("team_index"))
        type = TypeEnum(obj.get("type"))
        return TextMessage(message, sender, sent_at, squad_index, team_index, type)

    def to_dict(self) -> dict:
        result: dict = {}
        result["message"] = from_str(self.message)
        result["sender"] = from_str(self.sender)
        result["sent_at"] = self.sent_at.isoformat()
        result["squad_index"] = from_int(self.squad_index)
        result["team_index"] = from_int(self.team_index)
        result["type"] = to_enum(TypeEnum, self.type)
        return result


@dataclass
class Coordinate:
    map: Map
    players: List[Player]
    rounds: List[Round]
    server: Server
    text_messages: List[TextMessage]
    version: str

    @staticmethod
    def from_dict(obj: Any) -> 'Coordinate':
        assert isinstance(obj, dict)
        map = Map.from_dict(obj.get("map"))
        players = from_list(Player.from_dict, obj.get("players"))
        rounds = from_list(Round.from_dict, obj.get("rounds"))
        server = Server.from_dict(obj.get("server"))
        text_messages = from_list(TextMessage.from_dict, obj.get("text_messages"))
        version = from_str(obj.get("version"))
        return Coordinate(map, players, rounds, server, text_messages, version)

    def to_dict(self) -> dict:
        result: dict = {}
        result["map"] = to_class(Map, self.map)
        result["players"] = from_list(lambda x: to_class(Player, x), self.players)
        result["rounds"] = from_list(lambda x: to_class(Round, x), self.rounds)
        result["server"] = to_class(Server, self.server)
        result["text_messages"] = from_list(lambda x: to_class(TextMessage, x), self.text_messages)
        result["version"] = from_str(self.version)
        return result


def coordinate_from_dict(s: Any) -> Coordinate:
    return Coordinate.from_dict(s)


def coordinate_to_dict(x: Coordinate) -> Any:
    return to_class(Coordinate, x)
