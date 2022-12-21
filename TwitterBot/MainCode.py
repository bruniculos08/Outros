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

    actual_case = lines[0].split(",")
    print(actual_case)

    last_post_file = open(generalPath + "\\ultimoPostData.txt")
    last_post = last_post_file.readline()

    actual_date = datetime.now().date()
    last_post_date = datetime.strptime(last_post, "%Y-%m-%d").date()

    if(actual_date > last_post_date):
        if(actual_case[0] == "fim"):
            result = datetime.strptime(actual_case[2], "%Y-%m-%d").date() - actual_date
            print(f"Faltam {int(result.days/30)} meses e {result.days%30} dias para o fim do semestre na UDESC.")

    # print(datetime.now().date() <= datetime.strptime(last_post, "%Y-%m-%d").date())
    # print(datetime.today().date())

    # last_info = lines[0].split(",")

    # if datetime


if __name__ == '__main__':
    oindividualist = api()
    semestreUdesc()


    # tweet(oindividualist, "testando API meus caros (parte 02)...")