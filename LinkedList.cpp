#include "LinkedList.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
//jyfyrconecticjhjschb
Link* List_Create()
{
	Link* anchor = (Link *) malloc(sizeof(Link));
	if (!anchor)
		return NULL;

	anchor->next = NULL;
	anchor->value = 0; // meaningless, but we'll init it anyhow.
	return anchor;
}

List_ErrorCodes List_Find(Link const* anchor, List_DataType valueToFind, Link const** link)
{
	*link = anchor;
	while (*link != NULL && (*link)->value != valueToFind)
	{
		*link = (*link)->next;
	}
	if (*link == NULL)
		return NO_SUCH_ELEMENT;

	return SUCCESS;

}

List_ErrorCodes List_FindPrev(Link const* anchor, Link const* link, Link const ** prev)
{
	*prev = anchor;
	while ((*prev)->next != NULL && (*prev)->next != link)
	{
		*prev = (*prev)->next;
	}
	if ((*prev)->next != link)
		return NO_SUCH_ELEMENT;

	return SUCCESS;

}

List_ErrorCodes List_LastLink(Link const* anchor, Link const ** lastLink)
{
	List_ErrorCodes res = List_FindPrev(anchor, NULL, lastLink);
	if (res != SUCCESS)
		return res;

	if (*lastLink == anchor)
		return NO_SUCH_ELEMENT;

	return SUCCESS;
}

List_ErrorCodes List_Remove(Link const* anchor, Link* linkToRemove, bool isToFree)
{
	if (linkToRemove == NULL)
		return INVALID_PARAM;

	const Link* prev;
	List_ErrorCodes findStatus = List_FindPrev(anchor, linkToRemove, &prev);
	if (findStatus != SUCCESS)
		return findStatus;

	((Link*)prev)->next = linkToRemove->next;
	if (isToFree)
		free(linkToRemove);

	return SUCCESS;
}

void List_Free(Link* anchor)
{
	while (anchor->next != NULL)
	{
		List_Remove(anchor, anchor->next, true);
	}
	free(anchor);
}

List_ErrorCodes List_Insert(Link* anchor, List_DataType value)
{
	Link* link = (Link*)malloc(sizeof(Link));
	if (!link)
		return ALLOC_FAIL;
	link->value = value;
	link->next = anchor->next;
	anchor->next = link;
	return SUCCESS;
}

size_t List_Length(Link const* anchor)
{
	size_t count = 0;
	for (Link* l = anchor->next; l != NULL; l = l->next)
		count++;

	return count;
}

/// <summary>
/// Swaps valus of two links.
/// </summary>
List_ErrorCodes List_SwapLinkValues(Link* link_a, Link* link_b)
{
	List_DataType temp = link_a->value;
	link_a->value = link_b->value;
	link_b->value = temp;
	return SUCCESS;
}

/// <summary>
/// Returns a pointer to the smallest element in the list.
/// </summary>
/// <param name="anchor">list anchor.</param>
/// <param name="minValueLink"></param>
/// <returns>If list is empty, returns NO_SUCH_ELEMENT. Otherwise returns SUCCESS</returns>
List_ErrorCodes List_FindMinValueLink(Link const* anchor, Link** minValueLink)
{
	if (List_Length(anchor) == 0)
		return NO_SUCH_ELEMENT;
	*minValueLink = anchor->next;
	for (Link* l = (*minValueLink)->next; l != NULL; l = l->next)
	{
		if (l->value < (*minValueLink)->value)
			*minValueLink = l;
	}

	return SUCCESS;
}


List_ErrorCodes List_Sort(Link const* anchor)
{
	if (List_Length(anchor) == 0)
		return SUCCESS;
	Link* minValuLink;
	List_FindMinValueLink(anchor, &minValuLink);
	List_SwapLinkValues(anchor->next, minValuLink);
	return List_Sort(anchor->next);
}

List_ErrorCodes List_ToArray(Link const* anchor, List_DataType** outArray, size_t* outArraySize)
{
	size_t len = List_Length(anchor);
	if (0 == len)
	{
		*outArray = NULL;
		*outArraySize = 0;
		return SUCCESS;
	}

	*outArray = (List_DataType *)malloc(sizeof(anchor->value) * len);
	if ((*outArray) == NULL)
		return ALLOC_FAIL;

	*outArraySize = len;
	size_t currIdx = 0;
	for (Link* l = anchor->next; l != NULL; l = l->next)
	{
		(*outArray)[currIdx++] = l->value;
	}

	return SUCCESS;
}

void List_Print(Link const* anchor)
{
	printf("||->");
	for (Link* l = anchor->next; l != NULL; l = l->next)
	{
		printf("%p,", l->value);
	}
	printf("->||\n");
}