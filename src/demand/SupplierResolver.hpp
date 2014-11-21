#pragma once


#include <rod/Resolve.hpp>
#include <rod/TypeList.hpp>
#include <rod/annotation/Resolver.hpp>

#include <demand/Demand.hpp>
#include <demand/Supplier.hpp>
#include <demand/SupplierSelector.hpp>




namespace demand
{

	namespace detail
	{

		template< typename SupplierType >
		struct GetDemandedType;

		template< typename DemandedType >
		struct GetDemandedType< Supplier< DemandedType > >
		{
			using r = DemandedType;
		};
		
	}


	struct SupplierResolver
	{
		using Resolver = rod::annotation::Resolver< SupplierSelector >;

		template< typename SupplierType, typename Context >
		static
		SupplierType
		resolve( Context& context )
		{
			using DemandedType = typename detail::GetDemandedType< SupplierType >::r;
			
			return SupplierType( rod::resolve< Demand< DemandedType >& >( context ) );
		}
	};
	
}