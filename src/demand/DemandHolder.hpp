#pragma once


#include <rod/TypeList.hpp>




namespace demand
{

	template< typename DemandComponent >
	struct DemandHolder
	{
		using Dependencies = rod::TypeList<>;


		DemandComponent	object;

		DemandHolder()
		{}

		DemandHolder( DemandHolder< DemandComponent >&& other ):
		  object( std::move( other.object ) )
		{}

		DemandHolder( const DemandHolder< DemandComponent >& ) = delete;


		DemandComponent&
		get()
		{
			return object;
		}
	};
	
}