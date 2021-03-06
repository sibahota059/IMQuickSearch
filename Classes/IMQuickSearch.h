//
//  IMQuickSearch.h
//  IMQuickSearch
//
//  Created by Ben Gordon on 12/13/13.
//  Copyright (c) 2013 Intermark. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IMQuickSearchFilter.h"

@interface IMQuickSearch : NSObject

#pragma mark - Properties
@property (nonatomic, assign) float fuzziness;
@property (nonatomic, retain) NSArray *masterArray;

#pragma mark - Init
/**
 Initializes a new IMQuickSearchObject with an NSArray of IMQuickSearchFilter objects and a default fuzziness set to 0.
 @param filters - NSArray of IMQuickSearchFilter objects
 @returns IMQuickSearch
 */
- (instancetype)initWithFilters:(NSArray *)filters;


/**
 Initializes a new IMQuickSearchObject with an NSArray of IMQuickSearchFilter objects and a fuzziness value.
 @param filters - NSArray of IMQuickSearchFilter objects
 @param fuzziness - float between 0 and 1, where 0 is a direct match, and 1 gives more leeway
 @returns IMQuickSearch
 */
// No Fuzziness for Now
/*
- (instancetype)initWithFilters:(NSArray *)filters fuzziness:(float)fuzziness;
 */


#pragma mark - Filter Management
/**
 Adds a new IMQuickSearchFilter to search with.
 @param filter  - IMQuickSearchFilter
 */
- (void)addFilter:(IMQuickSearchFilter *)filter;

/**
 Removes a given filter.
 @param filter  - IMQuickSearchFilter
 */
- (void)removeFilter:(IMQuickSearchFilter *)filter;


#pragma mark - Filter
/**
 Filters all of the IMQuickSearchFilter objects with a given value. Each item in the array is unique.
 @param value   - A value to filter over
 @returns NSArray
 */
- (NSArray *)filteredObjectsWithValue:(id)value;

/**
 Filters all of the IMQuickSearchFilter objects with a given value asynchronously, and uses the completion block callback to present the items when finished. Each item in the array is unique.
 @param value   - A value to filter over
 @returns NSArray
 */
- (void)asynchronouslyFilterObjectsWithValue:(id)value completion:(void (^)(NSArray *filteredResults))completion;


@end
