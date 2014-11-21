#pragma once


#include <demand/Supplier.hpp>




namespace demand
{


	template< typename SupplierType >
	struct SupplierSelector;

	template< typename DemandedType >
	struct SupplierSelector< Supplier< DemandedType > >
	{
		enum { r = true };
	};

	template< typename OtherType >
	struct SupplierSelector
	{
		enum { r = false };
	};
	
}