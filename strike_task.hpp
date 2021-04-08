
#pragma once


#include <cstdint>
#include <iostream>
#include "uci/base/cal.hpp"
#include "example_base.hpp"

// References:
//    CMS (activemq-cpp) Overview : https://activemq.apache.org/components/cms/overview
//    CMS (activemq-cpp) pub/sub example : https://activemq.apache.org/components/cms/example
//    XSD (CodeSynthesis) getting started guide : https://www.codesynthesis.com/projects/xsd/documentation/cxx/tree/guide/
//    XSD (CodeSynthesis) manual : https://www.codesynthesis.com/projects/xsd/documentation/cxx/tree/manual/
//    XSD (CodeSynthesis) API reference : https://www.codesynthesis.com/projects/xsd/documentation/cxx/tree/reference/html/
//    XSD (CodeSynthesis) CLI reference: https://www.codesynthesis.com/projects/xsd/documentation/xsd.xhtml


class TaskExample : public ExampleBase<uci::TaskMT>
{
protected:
    class TaskListener : public uci::base::Listener
    {
    public:
        // ** example of how to listen for and handle a Task UCI message ** //
        virtual void handleMessage(const std::unique_ptr<uci::MessageType>& xsd_object)
        {
            const uci::TaskMT& task = static_cast<const uci::TaskMT&>(*xsd_object);
        }
    };

public:
    TaskExample():
    ExampleBase{ std::make_shared<TaskListener>(), "Task" }
    {
    }

    // ** example of how to create and populate a Task UCI message ** //
    uci::TaskMT populate_message()
    {
        try
        {
            // ** message header ** //
            uci::base::MessageHeader message_header = populate_header();

            // ** start message data ** //
            // task message data
            uci::base::ID system_id = message_header.SystemID();
            uci::base::ID task_id;
            uci::base::ID target_entity_id("DCAE0000000000000000000000000001", "");
            uci::TargetType target;
            target.EntityID(target_entity_id);
            uci::StrikeTaskWeaponListType weapon_list;
            uci::StrikeTaskWeaponListType::Weapon_sequence weapon_sequence;
            uci::StrikeTaskWeaponType weapon(0, 0, 0);
            weapon_sequence.push_back(weapon);
            weapon_list.Weapon(weapon_sequence);
            uci::StrikeTaskType strike(target);
            strike.WeaponList(weapon_list);
            uci::TaskType task_type;
            task_type.Strike(strike);
            // allocation requirement - i.e. the platform that should carry out the strike
            uci::TaskAllocationParametersType allocation_constraint;
            allocation_constraint.RequiredAllocation().push_back(uci::TaskAllocationConstraintType(system_id));
            uci::TaskMDT message_data(
                task_id,
                task_type,
                allocation_constraint,
                false // execution approval required
                );
            // ** end message data ** //

            // ** start task message ** //
            // required attributes
            ::all::CVEnumISMClassificationAll classification = ::all::CVEnumISMClassificationAll::U;
            ::ownerproducer::CVEnumISMOwnerProducer owner_producer = ::ownerproducer::CVEnumISMOwnerProducer_base(1, ::ownerproducer::CVEnumISMOwnerProducerValues::USA);
            // other required fields
            uci::MessageStateEnum message_state = uci::MessageStateEnum::NEW;
            // task message
            uci::TaskMT task(
                message_header,
                classification,
                owner_producer,
                message_state,
                message_data
                );
            // ** end task message ** //

            return task;
        }
        catch (const xml_schema::exception& e)
        {
            std::cerr << e << std::endl;
        }
    }
};
