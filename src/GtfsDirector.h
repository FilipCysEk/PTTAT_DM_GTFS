#ifndef PTTAT_GTFS_GTFSDIRECTOR_H
#define PTTAT_GTFS_GTFSDIRECTOR_H

#include <boost/config.hpp>
#include "DataManager/DataManager.h"

using namespace PFunctions;

namespace GtfsData{
    class GtfsDirector: public DataManager{
    public:
        void initialize(ConfigFile *config, shared_ptr <spdlog::logger> &logger,
                        unsigned short amountKeepOldVehiclePositions) override;

        ~GtfsDirector() override;

        void updateDb() override;

        void updateVehiclePositions() override;

    };

    extern "C" BOOST_SYMBOL_EXPORT GtfsData::GtfsDirector dataManagerSL;
    GtfsData::GtfsDirector dataManagerSL;
};

#endif //PTTAT_GTFS_GTFSDIRECTOR_H
