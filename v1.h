//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Coordinate data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"

#include <optional>
#include <stdexcept>
#include <regex>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json & j, const std::shared_ptr<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json & j) {
            if (j.is_null()) return std::unique_ptr<T>(); else return std::unique_ptr<T>(new T(j.get<T>()));
        }
    };
}
#endif

namespace darklight {
    using nlohmann::json;

    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, std::string property) {
        return get_optional<T>(j, property.data());
    }

    class Bounds {
        public:
        Bounds() = default;
        virtual ~Bounds() = default;

        private:
        std::vector<double> ne;
        std::vector<double> sw;

        public:
        const std::vector<double> & get_ne() const { return ne; }
        std::vector<double> & get_mutable_ne() { return ne; }
        void set_ne(const std::vector<double> & value) { this->ne = value; }

        const std::vector<double> & get_sw() const { return sw; }
        std::vector<double> & get_mutable_sw() { return sw; }
        void set_sw(const std::vector<double> & value) { this->sw = value; }
    };

    class Map {
        public:
        Map() = default;
        virtual ~Map() = default;

        private:
        Bounds bounds;
        std::string name;
        int64_t offset;

        public:
        const Bounds & get_bounds() const { return bounds; }
        Bounds & get_mutable_bounds() { return bounds; }
        void set_bounds(const Bounds & value) { this->bounds = value; }

        const std::string & get_name() const { return name; }
        std::string & get_mutable_name() { return name; }
        void set_name(const std::string & value) { this->name = value; }

        const int64_t & get_offset() const { return offset; }
        int64_t & get_mutable_offset() { return offset; }
        void set_offset(const int64_t & value) { this->offset = value; }
    };

    class Session {
        public:
        Session() = default;
        virtual ~Session() = default;

        private:
        std::string ended_at;
        std::string ip;
        std::string started_at;

        public:
        const std::string & get_ended_at() const { return ended_at; }
        std::string & get_mutable_ended_at() { return ended_at; }
        void set_ended_at(const std::string & value) { this->ended_at = value; }

        const std::string & get_ip() const { return ip; }
        std::string & get_mutable_ip() { return ip; }
        void set_ip(const std::string & value) { this->ip = value; }

        const std::string & get_started_at() const { return started_at; }
        std::string & get_mutable_started_at() { return started_at; }
        void set_started_at(const std::string & value) { this->started_at = value; }
    };

    class Player {
        public:
        Player() = default;
        virtual ~Player() = default;

        private:
        std::string id;
        std::vector<std::string> names;
        std::vector<Session> sessions;

        public:
        const std::string & get_id() const { return id; }
        std::string & get_mutable_id() { return id; }
        void set_id(const std::string & value) { this->id = value; }

        const std::vector<std::string> & get_names() const { return names; }
        std::vector<std::string> & get_mutable_names() { return names; }
        void set_names(const std::vector<std::string> & value) { this->names = value; }

        const std::vector<Session> & get_sessions() const { return sessions; }
        std::vector<Session> & get_mutable_sessions() { return sessions; }
        void set_sessions(const std::vector<Session> & value) { this->sessions = value; }
    };

    class Capture {
        public:
        Capture() = default;
        virtual ~Capture() = default;

        private:
        int64_t objective_id;
        std::vector<std::string> player_ids;
        int64_t round_time;
        int64_t team;

        public:
        const int64_t & get_objective_id() const { return objective_id; }
        int64_t & get_mutable_objective_id() { return objective_id; }
        void set_objective_id(const int64_t & value) { this->objective_id = value; }

        const std::vector<std::string> & get_player_ids() const { return player_ids; }
        std::vector<std::string> & get_mutable_player_ids() { return player_ids; }
        void set_player_ids(const std::vector<std::string> & value) { this->player_ids = value; }

        const int64_t & get_round_time() const { return round_time; }
        int64_t & get_mutable_round_time() { return round_time; }
        void set_round_time(const int64_t & value) { this->round_time = value; }

        const int64_t & get_team() const { return team; }
        int64_t & get_mutable_team() { return team; }
        void set_team(const int64_t & value) { this->team = value; }
    };

    class Construction {
        public:
        Construction() = default;
        virtual ~Construction() = default;

        private:
        std::string construction_class;
        std::vector<double> location;
        std::string player_id;
        int64_t round_time;
        int64_t team;

        public:
        const std::string & get_construction_class() const { return construction_class; }
        std::string & get_mutable_construction_class() { return construction_class; }
        void set_construction_class(const std::string & value) { this->construction_class = value; }

        const std::vector<double> & get_location() const { return location; }
        std::vector<double> & get_mutable_location() { return location; }
        void set_location(const std::vector<double> & value) { this->location = value; }

        const std::string & get_player_id() const { return player_id; }
        std::string & get_mutable_player_id() { return player_id; }
        void set_player_id(const std::string & value) { this->player_id = value; }

        const int64_t & get_round_time() const { return round_time; }
        int64_t & get_mutable_round_time() { return round_time; }
        void set_round_time(const int64_t & value) { this->round_time = value; }

        const int64_t & get_team() const { return team; }
        int64_t & get_mutable_team() { return team; }
        void set_team(const int64_t & value) { this->team = value; }
    };

    class Team {
        public:
        Team() = default;
        virtual ~Team() = default;

        private:
        double munitions;
        int64_t objectives_owned;
        int64_t reinforcements;
        int64_t size;
        int64_t team_index;

        public:
        const double & get_munitions() const { return munitions; }
        double & get_mutable_munitions() { return munitions; }
        void set_munitions(const double & value) { this->munitions = value; }

        const int64_t & get_objectives_owned() const { return objectives_owned; }
        int64_t & get_mutable_objectives_owned() { return objectives_owned; }
        void set_objectives_owned(const int64_t & value) { this->objectives_owned = value; }

        const int64_t & get_reinforcements() const { return reinforcements; }
        int64_t & get_mutable_reinforcements() { return reinforcements; }
        void set_reinforcements(const int64_t & value) { this->reinforcements = value; }

        const int64_t & get_size() const { return size; }
        int64_t & get_mutable_size() { return size; }
        void set_size(const int64_t & value) { this->size = value; }

        const int64_t & get_team_index() const { return team_index; }
        int64_t & get_mutable_team_index() { return team_index; }
        void set_team_index(const int64_t & value) { this->team_index = value; }
    };

    class RoundState {
        public:
        RoundState() = default;
        virtual ~RoundState() = default;

        private:
        int64_t round_time;
        std::vector<Team> teams;

        public:
        const int64_t & get_round_time() const { return round_time; }
        int64_t & get_mutable_round_time() { return round_time; }
        void set_round_time(const int64_t & value) { this->round_time = value; }

        const std::vector<Team> & get_teams() const { return teams; }
        std::vector<Team> & get_mutable_teams() { return teams; }
        void set_teams(const std::vector<Team> & value) { this->teams = value; }
    };

    class Vote {
        public:
        Vote() = default;
        virtual ~Vote() = default;

        private:
        int64_t option_id;
        std::vector<std::string> voter_ids;

        public:
        const int64_t & get_option_id() const { return option_id; }
        int64_t & get_mutable_option_id() { return option_id; }
        void set_option_id(const int64_t & value) { this->option_id = value; }

        const std::vector<std::string> & get_voter_ids() const { return voter_ids; }
        std::vector<std::string> & get_mutable_voter_ids() { return voter_ids; }
        void set_voter_ids(const std::vector<std::string> & value) { this->voter_ids = value; }
    };

    class Data {
        public:
        Data() = default;
        virtual ~Data() = default;

        private:
        std::string ended_at;
        std::vector<std::string> nominator_ids;
        int64_t result_id;
        RoundState round_state;
        std::string started_at;
        int64_t team_index;
        std::string vote_type;
        std::vector<Vote> votes;

        public:
        const std::string & get_ended_at() const { return ended_at; }
        std::string & get_mutable_ended_at() { return ended_at; }
        void set_ended_at(const std::string & value) { this->ended_at = value; }

        const std::vector<std::string> & get_nominator_ids() const { return nominator_ids; }
        std::vector<std::string> & get_mutable_nominator_ids() { return nominator_ids; }
        void set_nominator_ids(const std::vector<std::string> & value) { this->nominator_ids = value; }

        const int64_t & get_result_id() const { return result_id; }
        int64_t & get_mutable_result_id() { return result_id; }
        void set_result_id(const int64_t & value) { this->result_id = value; }

        const RoundState & get_round_state() const { return round_state; }
        RoundState & get_mutable_round_state() { return round_state; }
        void set_round_state(const RoundState & value) { this->round_state = value; }

        const std::string & get_started_at() const { return started_at; }
        std::string & get_mutable_started_at() { return started_at; }
        void set_started_at(const std::string & value) { this->started_at = value; }

        const int64_t & get_team_index() const { return team_index; }
        int64_t & get_mutable_team_index() { return team_index; }
        void set_team_index(const int64_t & value) { this->team_index = value; }

        const std::string & get_vote_type() const { return vote_type; }
        std::string & get_mutable_vote_type() { return vote_type; }
        void set_vote_type(const std::string & value) { this->vote_type = value; }

        const std::vector<Vote> & get_votes() const { return votes; }
        std::vector<Vote> & get_mutable_votes() { return votes; }
        void set_votes(const std::vector<Vote> & value) { this->votes = value; }
    };

    class Event {
        public:
        Event() = default;
        virtual ~Event() = default;

        private:
        Data data;
        std::string type;

        public:
        const Data & get_data() const { return data; }
        Data & get_mutable_data() { return data; }
        void set_data(const Data & value) { this->data = value; }

        const std::string & get_type() const { return type; }
        std::string & get_mutable_type() { return type; }
        void set_type(const std::string & value) { this->type = value; }
    };

    class Killer {
        public:
        Killer() = default;
        virtual ~Killer() = default;

        private:
        std::string id;
        std::vector<int64_t> location;
        std::shared_ptr<std::string> pawn;
        int64_t team;
        std::shared_ptr<std::string> vehicle;

        public:
        const std::string & get_id() const { return id; }
        std::string & get_mutable_id() { return id; }
        void set_id(const std::string & value) { this->id = value; }

        const std::vector<int64_t> & get_location() const { return location; }
        std::vector<int64_t> & get_mutable_location() { return location; }
        void set_location(const std::vector<int64_t> & value) { this->location = value; }

        std::shared_ptr<std::string> get_pawn() const { return pawn; }
        void set_pawn(std::shared_ptr<std::string> value) { this->pawn = value; }

        const int64_t & get_team() const { return team; }
        int64_t & get_mutable_team() { return team; }
        void set_team(const int64_t & value) { this->team = value; }

        std::shared_ptr<std::string> get_vehicle() const { return vehicle; }
        void set_vehicle(std::shared_ptr<std::string> value) { this->vehicle = value; }
    };

    class Frag {
        public:
        Frag() = default;
        virtual ~Frag() = default;

        private:
        std::string damage_type;
        int64_t hit_index;
        Killer killer;
        int64_t time;
        Killer victim;

        public:
        const std::string & get_damage_type() const { return damage_type; }
        std::string & get_mutable_damage_type() { return damage_type; }
        void set_damage_type(const std::string & value) { this->damage_type = value; }

        const int64_t & get_hit_index() const { return hit_index; }
        int64_t & get_mutable_hit_index() { return hit_index; }
        void set_hit_index(const int64_t & value) { this->hit_index = value; }

        const Killer & get_killer() const { return killer; }
        Killer & get_mutable_killer() { return killer; }
        void set_killer(const Killer & value) { this->killer = value; }

        const int64_t & get_time() const { return time; }
        int64_t & get_mutable_time() { return time; }
        void set_time(const int64_t & value) { this->time = value; }

        const Killer & get_victim() const { return victim; }
        Killer & get_mutable_victim() { return victim; }
        void set_victim(const Killer & value) { this->victim = value; }
    };

    enum class DestroyedReason : int { ABANDONED, DAMAGED, DELETED, ENCROACHED, EXHAUSTED, OVERRUN, REPLACED, SPAWN_KILL };

    class RallyPoint {
        public:
        RallyPoint() = default;
        virtual ~RallyPoint() = default;

        private:
        std::string created_at;
        std::shared_ptr<std::string> destroyed_at;
        std::shared_ptr<DestroyedReason> destroyed_reason;
        int64_t establisher_count;
        bool is_established;
        std::vector<double> location;
        std::string player_id;
        int64_t spawn_count;
        int64_t squad_index;
        int64_t team_index;

        public:
        const std::string & get_created_at() const { return created_at; }
        std::string & get_mutable_created_at() { return created_at; }
        void set_created_at(const std::string & value) { this->created_at = value; }

        std::shared_ptr<std::string> get_destroyed_at() const { return destroyed_at; }
        void set_destroyed_at(std::shared_ptr<std::string> value) { this->destroyed_at = value; }

        std::shared_ptr<DestroyedReason> get_destroyed_reason() const { return destroyed_reason; }
        void set_destroyed_reason(std::shared_ptr<DestroyedReason> value) { this->destroyed_reason = value; }

        const int64_t & get_establisher_count() const { return establisher_count; }
        int64_t & get_mutable_establisher_count() { return establisher_count; }
        void set_establisher_count(const int64_t & value) { this->establisher_count = value; }

        const bool & get_is_established() const { return is_established; }
        bool & get_mutable_is_established() { return is_established; }
        void set_is_established(const bool & value) { this->is_established = value; }

        const std::vector<double> & get_location() const { return location; }
        std::vector<double> & get_mutable_location() { return location; }
        void set_location(const std::vector<double> & value) { this->location = value; }

        const std::string & get_player_id() const { return player_id; }
        std::string & get_mutable_player_id() { return player_id; }
        void set_player_id(const std::string & value) { this->player_id = value; }

        const int64_t & get_spawn_count() const { return spawn_count; }
        int64_t & get_mutable_spawn_count() { return spawn_count; }
        void set_spawn_count(const int64_t & value) { this->spawn_count = value; }

        const int64_t & get_squad_index() const { return squad_index; }
        int64_t & get_mutable_squad_index() { return squad_index; }
        void set_squad_index(const int64_t & value) { this->squad_index = value; }

        const int64_t & get_team_index() const { return team_index; }
        int64_t & get_mutable_team_index() { return team_index; }
        void set_team_index(const int64_t & value) { this->team_index = value; }
    };

    class DestroyedVehicle {
        public:
        DestroyedVehicle() = default;
        virtual ~DestroyedVehicle() = default;

        private:
        std::vector<int64_t> location;
        int64_t team;
        std::string vehicle;

        public:
        const std::vector<int64_t> & get_location() const { return location; }
        std::vector<int64_t> & get_mutable_location() { return location; }
        void set_location(const std::vector<int64_t> & value) { this->location = value; }

        const int64_t & get_team() const { return team; }
        int64_t & get_mutable_team() { return team; }
        void set_team(const int64_t & value) { this->team = value; }

        const std::string & get_vehicle() const { return vehicle; }
        std::string & get_mutable_vehicle() { return vehicle; }
        void set_vehicle(const std::string & value) { this->vehicle = value; }
    };

    class VehicleFrag {
        public:
        VehicleFrag() = default;
        virtual ~VehicleFrag() = default;

        private:
        std::string damage_type;
        DestroyedVehicle destroyed_vehicle;
        Killer killer;
        int64_t time;

        public:
        const std::string & get_damage_type() const { return damage_type; }
        std::string & get_mutable_damage_type() { return damage_type; }
        void set_damage_type(const std::string & value) { this->damage_type = value; }

        const DestroyedVehicle & get_destroyed_vehicle() const { return destroyed_vehicle; }
        DestroyedVehicle & get_mutable_destroyed_vehicle() { return destroyed_vehicle; }
        void set_destroyed_vehicle(const DestroyedVehicle & value) { this->destroyed_vehicle = value; }

        const Killer & get_killer() const { return killer; }
        Killer & get_mutable_killer() { return killer; }
        void set_killer(const Killer & value) { this->killer = value; }

        const int64_t & get_time() const { return time; }
        int64_t & get_mutable_time() { return time; }
        void set_time(const int64_t & value) { this->time = value; }
    };

    class Round {
        public:
        Round() = default;
        virtual ~Round() = default;

        private:
        std::vector<Capture> captures;
        std::vector<Construction> constructions;
        std::string ended_at;
        std::vector<Event> events;
        std::vector<Frag> frags;
        std::vector<RallyPoint> rally_points;
        std::string started_at;
        std::vector<VehicleFrag> vehicle_frags;
        int64_t winner;

        public:
        const std::vector<Capture> & get_captures() const { return captures; }
        std::vector<Capture> & get_mutable_captures() { return captures; }
        void set_captures(const std::vector<Capture> & value) { this->captures = value; }

        const std::vector<Construction> & get_constructions() const { return constructions; }
        std::vector<Construction> & get_mutable_constructions() { return constructions; }
        void set_constructions(const std::vector<Construction> & value) { this->constructions = value; }

        const std::string & get_ended_at() const { return ended_at; }
        std::string & get_mutable_ended_at() { return ended_at; }
        void set_ended_at(const std::string & value) { this->ended_at = value; }

        const std::vector<Event> & get_events() const { return events; }
        std::vector<Event> & get_mutable_events() { return events; }
        void set_events(const std::vector<Event> & value) { this->events = value; }

        const std::vector<Frag> & get_frags() const { return frags; }
        std::vector<Frag> & get_mutable_frags() { return frags; }
        void set_frags(const std::vector<Frag> & value) { this->frags = value; }

        const std::vector<RallyPoint> & get_rally_points() const { return rally_points; }
        std::vector<RallyPoint> & get_mutable_rally_points() { return rally_points; }
        void set_rally_points(const std::vector<RallyPoint> & value) { this->rally_points = value; }

        const std::string & get_started_at() const { return started_at; }
        std::string & get_mutable_started_at() { return started_at; }
        void set_started_at(const std::string & value) { this->started_at = value; }

        const std::vector<VehicleFrag> & get_vehicle_frags() const { return vehicle_frags; }
        std::vector<VehicleFrag> & get_mutable_vehicle_frags() { return vehicle_frags; }
        void set_vehicle_frags(const std::vector<VehicleFrag> & value) { this->vehicle_frags = value; }

        const int64_t & get_winner() const { return winner; }
        int64_t & get_mutable_winner() { return winner; }
        void set_winner(const int64_t & value) { this->winner = value; }
    };

    class Server {
        public:
        Server() = default;
        virtual ~Server() = default;

        private:
        std::string name;

        public:
        const std::string & get_name() const { return name; }
        std::string & get_mutable_name() { return name; }
        void set_name(const std::string & value) { this->name = value; }
    };

    enum class Type : int { COMMAND_SAY, SAY, SQUAD_SAY, TEAM_SAY, VEHICLE_SAY };

    class TextMessage {
        public:
        TextMessage() = default;
        virtual ~TextMessage() = default;

        private:
        std::string message;
        std::string sender;
        std::string sent_at;
        int64_t squad_index;
        int64_t team_index;
        Type type;

        public:
        const std::string & get_message() const { return message; }
        std::string & get_mutable_message() { return message; }
        void set_message(const std::string & value) { this->message = value; }

        const std::string & get_sender() const { return sender; }
        std::string & get_mutable_sender() { return sender; }
        void set_sender(const std::string & value) { this->sender = value; }

        const std::string & get_sent_at() const { return sent_at; }
        std::string & get_mutable_sent_at() { return sent_at; }
        void set_sent_at(const std::string & value) { this->sent_at = value; }

        const int64_t & get_squad_index() const { return squad_index; }
        int64_t & get_mutable_squad_index() { return squad_index; }
        void set_squad_index(const int64_t & value) { this->squad_index = value; }

        const int64_t & get_team_index() const { return team_index; }
        int64_t & get_mutable_team_index() { return team_index; }
        void set_team_index(const int64_t & value) { this->team_index = value; }

        const Type & get_type() const { return type; }
        Type & get_mutable_type() { return type; }
        void set_type(const Type & value) { this->type = value; }
    };

    class Coordinate {
        public:
        Coordinate() = default;
        virtual ~Coordinate() = default;

        private:
        Map map;
        std::vector<Player> players;
        std::vector<Round> rounds;
        Server server;
        std::vector<TextMessage> text_messages;
        std::string version;

        public:
        const Map & get_map() const { return map; }
        Map & get_mutable_map() { return map; }
        void set_map(const Map & value) { this->map = value; }

        const std::vector<Player> & get_players() const { return players; }
        std::vector<Player> & get_mutable_players() { return players; }
        void set_players(const std::vector<Player> & value) { this->players = value; }

        const std::vector<Round> & get_rounds() const { return rounds; }
        std::vector<Round> & get_mutable_rounds() { return rounds; }
        void set_rounds(const std::vector<Round> & value) { this->rounds = value; }

        const Server & get_server() const { return server; }
        Server & get_mutable_server() { return server; }
        void set_server(const Server & value) { this->server = value; }

        const std::vector<TextMessage> & get_text_messages() const { return text_messages; }
        std::vector<TextMessage> & get_mutable_text_messages() { return text_messages; }
        void set_text_messages(const std::vector<TextMessage> & value) { this->text_messages = value; }

        const std::string & get_version() const { return version; }
        std::string & get_mutable_version() { return version; }
        void set_version(const std::string & value) { this->version = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, darklight::Bounds & x);
    void to_json(json & j, const darklight::Bounds & x);

    void from_json(const json & j, darklight::Map & x);
    void to_json(json & j, const darklight::Map & x);

    void from_json(const json & j, darklight::Session & x);
    void to_json(json & j, const darklight::Session & x);

    void from_json(const json & j, darklight::Player & x);
    void to_json(json & j, const darklight::Player & x);

    void from_json(const json & j, darklight::Capture & x);
    void to_json(json & j, const darklight::Capture & x);

    void from_json(const json & j, darklight::Construction & x);
    void to_json(json & j, const darklight::Construction & x);

    void from_json(const json & j, darklight::Team & x);
    void to_json(json & j, const darklight::Team & x);

    void from_json(const json & j, darklight::RoundState & x);
    void to_json(json & j, const darklight::RoundState & x);

    void from_json(const json & j, darklight::Vote & x);
    void to_json(json & j, const darklight::Vote & x);

    void from_json(const json & j, darklight::Data & x);
    void to_json(json & j, const darklight::Data & x);

    void from_json(const json & j, darklight::Event & x);
    void to_json(json & j, const darklight::Event & x);

    void from_json(const json & j, darklight::Killer & x);
    void to_json(json & j, const darklight::Killer & x);

    void from_json(const json & j, darklight::Frag & x);
    void to_json(json & j, const darklight::Frag & x);

    void from_json(const json & j, darklight::RallyPoint & x);
    void to_json(json & j, const darklight::RallyPoint & x);

    void from_json(const json & j, darklight::DestroyedVehicle & x);
    void to_json(json & j, const darklight::DestroyedVehicle & x);

    void from_json(const json & j, darklight::VehicleFrag & x);
    void to_json(json & j, const darklight::VehicleFrag & x);

    void from_json(const json & j, darklight::Round & x);
    void to_json(json & j, const darklight::Round & x);

    void from_json(const json & j, darklight::Server & x);
    void to_json(json & j, const darklight::Server & x);

    void from_json(const json & j, darklight::TextMessage & x);
    void to_json(json & j, const darklight::TextMessage & x);

    void from_json(const json & j, darklight::Coordinate & x);
    void to_json(json & j, const darklight::Coordinate & x);

    void from_json(const json & j, darklight::DestroyedReason & x);
    void to_json(json & j, const darklight::DestroyedReason & x);

    void from_json(const json & j, darklight::Type & x);
    void to_json(json & j, const darklight::Type & x);

    inline void from_json(const json & j, darklight::Bounds& x) {
        x.set_ne(j.at("ne").get<std::vector<double>>());
        x.set_sw(j.at("sw").get<std::vector<double>>());
    }

    inline void to_json(json & j, const darklight::Bounds & x) {
        j = json::object();
        j["ne"] = x.get_ne();
        j["sw"] = x.get_sw();
    }

    inline void from_json(const json & j, darklight::Map& x) {
        x.set_bounds(j.at("bounds").get<darklight::Bounds>());
        x.set_name(j.at("name").get<std::string>());
        x.set_offset(j.at("offset").get<int64_t>());
    }

    inline void to_json(json & j, const darklight::Map & x) {
        j = json::object();
        j["bounds"] = x.get_bounds();
        j["name"] = x.get_name();
        j["offset"] = x.get_offset();
    }

    inline void from_json(const json & j, darklight::Session& x) {
        x.set_ended_at(j.at("ended_at").get<std::string>());
        x.set_ip(j.at("ip").get<std::string>());
        x.set_started_at(j.at("started_at").get<std::string>());
    }

    inline void to_json(json & j, const darklight::Session & x) {
        j = json::object();
        j["ended_at"] = x.get_ended_at();
        j["ip"] = x.get_ip();
        j["started_at"] = x.get_started_at();
    }

    inline void from_json(const json & j, darklight::Player& x) {
        x.set_id(j.at("id").get<std::string>());
        x.set_names(j.at("names").get<std::vector<std::string>>());
        x.set_sessions(j.at("sessions").get<std::vector<darklight::Session>>());
    }

    inline void to_json(json & j, const darklight::Player & x) {
        j = json::object();
        j["id"] = x.get_id();
        j["names"] = x.get_names();
        j["sessions"] = x.get_sessions();
    }

    inline void from_json(const json & j, darklight::Capture& x) {
        x.set_objective_id(j.at("objective_id").get<int64_t>());
        x.set_player_ids(j.at("player_ids").get<std::vector<std::string>>());
        x.set_round_time(j.at("round_time").get<int64_t>());
        x.set_team(j.at("team").get<int64_t>());
    }

    inline void to_json(json & j, const darklight::Capture & x) {
        j = json::object();
        j["objective_id"] = x.get_objective_id();
        j["player_ids"] = x.get_player_ids();
        j["round_time"] = x.get_round_time();
        j["team"] = x.get_team();
    }

    inline void from_json(const json & j, darklight::Construction& x) {
        x.set_construction_class(j.at("class").get<std::string>());
        x.set_location(j.at("location").get<std::vector<double>>());
        x.set_player_id(j.at("player_id").get<std::string>());
        x.set_round_time(j.at("round_time").get<int64_t>());
        x.set_team(j.at("team").get<int64_t>());
    }

    inline void to_json(json & j, const darklight::Construction & x) {
        j = json::object();
        j["class"] = x.get_construction_class();
        j["location"] = x.get_location();
        j["player_id"] = x.get_player_id();
        j["round_time"] = x.get_round_time();
        j["team"] = x.get_team();
    }

    inline void from_json(const json & j, darklight::Team& x) {
        x.set_munitions(j.at("munitions").get<double>());
        x.set_objectives_owned(j.at("objectives_owned").get<int64_t>());
        x.set_reinforcements(j.at("reinforcements").get<int64_t>());
        x.set_size(j.at("size").get<int64_t>());
        x.set_team_index(j.at("team_index").get<int64_t>());
    }

    inline void to_json(json & j, const darklight::Team & x) {
        j = json::object();
        j["munitions"] = x.get_munitions();
        j["objectives_owned"] = x.get_objectives_owned();
        j["reinforcements"] = x.get_reinforcements();
        j["size"] = x.get_size();
        j["team_index"] = x.get_team_index();
    }

    inline void from_json(const json & j, darklight::RoundState& x) {
        x.set_round_time(j.at("round_time").get<int64_t>());
        x.set_teams(j.at("teams").get<std::vector<darklight::Team>>());
    }

    inline void to_json(json & j, const darklight::RoundState & x) {
        j = json::object();
        j["round_time"] = x.get_round_time();
        j["teams"] = x.get_teams();
    }

    inline void from_json(const json & j, darklight::Vote& x) {
        x.set_option_id(j.at("option_id").get<int64_t>());
        x.set_voter_ids(j.at("voter_ids").get<std::vector<std::string>>());
    }

    inline void to_json(json & j, const darklight::Vote & x) {
        j = json::object();
        j["option_id"] = x.get_option_id();
        j["voter_ids"] = x.get_voter_ids();
    }

    inline void from_json(const json & j, darklight::Data& x) {
        x.set_ended_at(j.at("ended_at").get<std::string>());
        x.set_nominator_ids(j.at("nominator_ids").get<std::vector<std::string>>());
        x.set_result_id(j.at("result_id").get<int64_t>());
        x.set_round_state(j.at("round_state").get<darklight::RoundState>());
        x.set_started_at(j.at("started_at").get<std::string>());
        x.set_team_index(j.at("team_index").get<int64_t>());
        x.set_vote_type(j.at("vote_type").get<std::string>());
        x.set_votes(j.at("votes").get<std::vector<darklight::Vote>>());
    }

    inline void to_json(json & j, const darklight::Data & x) {
        j = json::object();
        j["ended_at"] = x.get_ended_at();
        j["nominator_ids"] = x.get_nominator_ids();
        j["result_id"] = x.get_result_id();
        j["round_state"] = x.get_round_state();
        j["started_at"] = x.get_started_at();
        j["team_index"] = x.get_team_index();
        j["vote_type"] = x.get_vote_type();
        j["votes"] = x.get_votes();
    }

    inline void from_json(const json & j, darklight::Event& x) {
        x.set_data(j.at("data").get<darklight::Data>());
        x.set_type(j.at("type").get<std::string>());
    }

    inline void to_json(json & j, const darklight::Event & x) {
        j = json::object();
        j["data"] = x.get_data();
        j["type"] = x.get_type();
    }

    inline void from_json(const json & j, darklight::Killer& x) {
        x.set_id(j.at("id").get<std::string>());
        x.set_location(j.at("location").get<std::vector<int64_t>>());
        x.set_pawn(darklight::get_optional<std::string>(j, "pawn"));
        x.set_team(j.at("team").get<int64_t>());
        x.set_vehicle(darklight::get_optional<std::string>(j, "vehicle"));
    }

    inline void to_json(json & j, const darklight::Killer & x) {
        j = json::object();
        j["id"] = x.get_id();
        j["location"] = x.get_location();
        j["pawn"] = x.get_pawn();
        j["team"] = x.get_team();
        j["vehicle"] = x.get_vehicle();
    }

    inline void from_json(const json & j, darklight::Frag& x) {
        x.set_damage_type(j.at("damage_type").get<std::string>());
        x.set_hit_index(j.at("hit_index").get<int64_t>());
        x.set_killer(j.at("killer").get<darklight::Killer>());
        x.set_time(j.at("time").get<int64_t>());
        x.set_victim(j.at("victim").get<darklight::Killer>());
    }

    inline void to_json(json & j, const darklight::Frag & x) {
        j = json::object();
        j["damage_type"] = x.get_damage_type();
        j["hit_index"] = x.get_hit_index();
        j["killer"] = x.get_killer();
        j["time"] = x.get_time();
        j["victim"] = x.get_victim();
    }

    inline void from_json(const json & j, darklight::RallyPoint& x) {
        x.set_created_at(j.at("created_at").get<std::string>());
        x.set_destroyed_at(darklight::get_optional<std::string>(j, "destroyed_at"));
        x.set_destroyed_reason(darklight::get_optional<darklight::DestroyedReason>(j, "destroyed_reason"));
        x.set_establisher_count(j.at("establisher_count").get<int64_t>());
        x.set_is_established(j.at("is_established").get<bool>());
        x.set_location(j.at("location").get<std::vector<double>>());
        x.set_player_id(j.at("player_id").get<std::string>());
        x.set_spawn_count(j.at("spawn_count").get<int64_t>());
        x.set_squad_index(j.at("squad_index").get<int64_t>());
        x.set_team_index(j.at("team_index").get<int64_t>());
    }

    inline void to_json(json & j, const darklight::RallyPoint & x) {
        j = json::object();
        j["created_at"] = x.get_created_at();
        j["destroyed_at"] = x.get_destroyed_at();
        j["destroyed_reason"] = x.get_destroyed_reason();
        j["establisher_count"] = x.get_establisher_count();
        j["is_established"] = x.get_is_established();
        j["location"] = x.get_location();
        j["player_id"] = x.get_player_id();
        j["spawn_count"] = x.get_spawn_count();
        j["squad_index"] = x.get_squad_index();
        j["team_index"] = x.get_team_index();
    }

    inline void from_json(const json & j, darklight::DestroyedVehicle& x) {
        x.set_location(j.at("location").get<std::vector<int64_t>>());
        x.set_team(j.at("team").get<int64_t>());
        x.set_vehicle(j.at("vehicle").get<std::string>());
    }

    inline void to_json(json & j, const darklight::DestroyedVehicle & x) {
        j = json::object();
        j["location"] = x.get_location();
        j["team"] = x.get_team();
        j["vehicle"] = x.get_vehicle();
    }

    inline void from_json(const json & j, darklight::VehicleFrag& x) {
        x.set_damage_type(j.at("damage_type").get<std::string>());
        x.set_destroyed_vehicle(j.at("destroyed_vehicle").get<darklight::DestroyedVehicle>());
        x.set_killer(j.at("killer").get<darklight::Killer>());
        x.set_time(j.at("time").get<int64_t>());
    }

    inline void to_json(json & j, const darklight::VehicleFrag & x) {
        j = json::object();
        j["damage_type"] = x.get_damage_type();
        j["destroyed_vehicle"] = x.get_destroyed_vehicle();
        j["killer"] = x.get_killer();
        j["time"] = x.get_time();
    }

    inline void from_json(const json & j, darklight::Round& x) {
        x.set_captures(j.at("captures").get<std::vector<darklight::Capture>>());
        x.set_constructions(j.at("constructions").get<std::vector<darklight::Construction>>());
        x.set_ended_at(j.at("ended_at").get<std::string>());
        x.set_events(j.at("events").get<std::vector<darklight::Event>>());
        x.set_frags(j.at("frags").get<std::vector<darklight::Frag>>());
        x.set_rally_points(j.at("rally_points").get<std::vector<darklight::RallyPoint>>());
        x.set_started_at(j.at("started_at").get<std::string>());
        x.set_vehicle_frags(j.at("vehicle_frags").get<std::vector<darklight::VehicleFrag>>());
        x.set_winner(j.at("winner").get<int64_t>());
    }

    inline void to_json(json & j, const darklight::Round & x) {
        j = json::object();
        j["captures"] = x.get_captures();
        j["constructions"] = x.get_constructions();
        j["ended_at"] = x.get_ended_at();
        j["events"] = x.get_events();
        j["frags"] = x.get_frags();
        j["rally_points"] = x.get_rally_points();
        j["started_at"] = x.get_started_at();
        j["vehicle_frags"] = x.get_vehicle_frags();
        j["winner"] = x.get_winner();
    }

    inline void from_json(const json & j, darklight::Server& x) {
        x.set_name(j.at("name").get<std::string>());
    }

    inline void to_json(json & j, const darklight::Server & x) {
        j = json::object();
        j["name"] = x.get_name();
    }

    inline void from_json(const json & j, darklight::TextMessage& x) {
        x.set_message(j.at("message").get<std::string>());
        x.set_sender(j.at("sender").get<std::string>());
        x.set_sent_at(j.at("sent_at").get<std::string>());
        x.set_squad_index(j.at("squad_index").get<int64_t>());
        x.set_team_index(j.at("team_index").get<int64_t>());
        x.set_type(j.at("type").get<darklight::Type>());
    }

    inline void to_json(json & j, const darklight::TextMessage & x) {
        j = json::object();
        j["message"] = x.get_message();
        j["sender"] = x.get_sender();
        j["sent_at"] = x.get_sent_at();
        j["squad_index"] = x.get_squad_index();
        j["team_index"] = x.get_team_index();
        j["type"] = x.get_type();
    }

    inline void from_json(const json & j, darklight::Coordinate& x) {
        x.set_map(j.at("map").get<darklight::Map>());
        x.set_players(j.at("players").get<std::vector<darklight::Player>>());
        x.set_rounds(j.at("rounds").get<std::vector<darklight::Round>>());
        x.set_server(j.at("server").get<darklight::Server>());
        x.set_text_messages(j.at("text_messages").get<std::vector<darklight::TextMessage>>());
        x.set_version(j.at("version").get<std::string>());
    }

    inline void to_json(json & j, const darklight::Coordinate & x) {
        j = json::object();
        j["map"] = x.get_map();
        j["players"] = x.get_players();
        j["rounds"] = x.get_rounds();
        j["server"] = x.get_server();
        j["text_messages"] = x.get_text_messages();
        j["version"] = x.get_version();
    }

    inline void from_json(const json & j, darklight::DestroyedReason & x) {
        if (j == "abandoned") x = darklight::DestroyedReason::ABANDONED;
        else if (j == "damaged") x = darklight::DestroyedReason::DAMAGED;
        else if (j == "deleted") x = darklight::DestroyedReason::DELETED;
        else if (j == "encroached") x = darklight::DestroyedReason::ENCROACHED;
        else if (j == "exhausted") x = darklight::DestroyedReason::EXHAUSTED;
        else if (j == "overrun") x = darklight::DestroyedReason::OVERRUN;
        else if (j == "replaced") x = darklight::DestroyedReason::REPLACED;
        else if (j == "spawn_kill") x = darklight::DestroyedReason::SPAWN_KILL;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const darklight::DestroyedReason & x) {
        switch (x) {
            case darklight::DestroyedReason::ABANDONED: j = "abandoned"; break;
            case darklight::DestroyedReason::DAMAGED: j = "damaged"; break;
            case darklight::DestroyedReason::DELETED: j = "deleted"; break;
            case darklight::DestroyedReason::ENCROACHED: j = "encroached"; break;
            case darklight::DestroyedReason::EXHAUSTED: j = "exhausted"; break;
            case darklight::DestroyedReason::OVERRUN: j = "overrun"; break;
            case darklight::DestroyedReason::REPLACED: j = "replaced"; break;
            case darklight::DestroyedReason::SPAWN_KILL: j = "spawn_kill"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, darklight::Type & x) {
        if (j == "CommandSay") x = darklight::Type::COMMAND_SAY;
        else if (j == "Say") x = darklight::Type::SAY;
        else if (j == "SquadSay") x = darklight::Type::SQUAD_SAY;
        else if (j == "TeamSay") x = darklight::Type::TEAM_SAY;
        else if (j == "VehicleSay") x = darklight::Type::VEHICLE_SAY;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const darklight::Type & x) {
        switch (x) {
            case darklight::Type::COMMAND_SAY: j = "CommandSay"; break;
            case darklight::Type::SAY: j = "Say"; break;
            case darklight::Type::SQUAD_SAY: j = "SquadSay"; break;
            case darklight::Type::TEAM_SAY: j = "TeamSay"; break;
            case darklight::Type::VEHICLE_SAY: j = "VehicleSay"; break;
            default: throw "This should not happen";
        }
    }
}
