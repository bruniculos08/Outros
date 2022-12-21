"""
Doing a twitter bot just for funny.
"""
import Keys as keys
import tweepy as tweepy
from datetime import datetime
# Caminho para a pasta deste código:
generalPath = "C:\\Users\\bruni\\OneDrive\\Documentos\\GitHub\\Outros\\TwitterBot"

def api():
    """
    To open the API principal object, first we need to create a object to realize the authentication
    needed to create the API principal object. The following object receives all the necessary keys and
    tokens for the authentication process:
    """
    authentication = tweepy.OAuthHandler(keys.API_key, keys.API_key_secret)
    authentication.set_access_token(keys.acess_token, keys.acess_token_secret)
    """
    Return the API principal object with the authentication realized (the constructor method needs the
    authentication to be created):
    """
    return tweepy.API(authentication)

def tweet(api: tweepy.API, message: str, image_path = None):
    if image_path:
        api.update_status_with_media(message, image_path)
    else:
        api.update_status(message)
    print("Tweet successfully!")

def semestreUdesc():
    semesters_file = open(generalPath + "\\semestres.txt")
    lines = semesters_file.readlines()

    with open(generalPath + "\\ultimoPostData.txt") as f:
        last_post = f.readline()

    print(datetime.now() < datetime.strptime(last_post, "%Y-%m-%d %H:%M:%S"))
    print(datetime.now())



    # last_info = lines[0].split(",")

    # if datetime


if __name__ == '__main__':
    oindividualist = api()
    semestreUdesc()


    # tweet(oindividualist, "testando API meus caros (parte 02)...")