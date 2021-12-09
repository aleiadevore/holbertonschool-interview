#!/usr/bin/python3
""" Prints number of keywords given for a subreddits hot list """
import json
import requests


def count_words(subreddit, word_list, after=None, answer_dict={}):
    """ Prints number of keywords given for a subreddits hot list """

    # subreddit: subreddit to check
    # word_list: set of keywords to check for

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "user"}
    parameters = {"show": "all", "next": "next", "after": after}

    try:
            response = requests.get(url, headers=headers,
                                    allow_redirects=False,
                                    params=parameters).json()
    except:
            return

    for item in word_list:
        # adding all keywords to answer_dict with a count of 0
        if item.lower() not in answer_dict:
            # adding all keywords to answer_dict with a count of 0
            answer_dict[item.lower()] = 0

    # Accounting for errors
    if "data" not in response:
        return

    for i in response.get("data")["children"]:
        # Get all titles, split by space
        check_list = i["data"]["title"].split()
        for key, value in answer_dict.items():
            # Checking words in titles against given keywords
            for item in check_list:
                # If keyword found, increase count by 1
                if key == item.lower():
                    answer_dict[key] += 1

    # Saving next page
    after = response.get("data").get("after")

    if not after:
        # no more pages to check, print answers
        for key, value in sorted(
            answer_dict.items(),
                key=lambda item: item[1], reverse=True):
                if value != 0:
                    print("{}: {}".format(key, value))
        return

    # If there are more pages to check, make recursive call
    return count_words(subreddit, word_list, after, answer_dict)
