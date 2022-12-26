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

def semestreUdesc(oindividualist):
    semesters_file = open(generalPath + "\\semestres.txt")
    lines = semesters_file.readlines()
    actual_case = lines[0].split(",")
    semesters_file.close()

    print(actual_case)

    last_post_file = open(generalPath + "\\ultimoPostData.txt", mode="r")
    last_post = last_post_file.readline()
    last_post_file.close()

    actual_date = datetime.now().date()
    last_post_date = datetime.strptime(last_post, "%Y-%m-%d").date()

    if(actual_date >= datetime.strptime(actual_case[2], "%Y-%m-%d").date()):
        semesters_file = open(generalPath + "\semestres.txt", mode="w")
        semesters_file.writelines(lines[1:])

    if(actual_date >= last_post_date):
        result = abs(datetime.strptime(actual_case[2], "%Y-%m-%d").date() - actual_date)
        if(actual_case[0] == "fim"):
            string = f"Faltam {abs(int(result.days/30))} meses e {result.days%30} dias para o fim do semestre na UDESC."
            print(string)
            # tweet(oindividualist, string)
        else:
            print(result)
            string = f"Faltam {abs(int(result.days/30))} meses e {result.days%30} dias para o início do semestre na UDESC."
            print(string)
            # tweet(oindividualist, string)

        last_post_date = actual_date
        last_post_file = open(generalPath + "\\ultimoPostData.txt", mode="w")
        last_post_file.write(str(last_post_date))

if __name__ == '__main__':
    oindividualist = api()
    #while(True):
    semestreUdesc(oindividualist)
    # tweet(oindividualist, "testando API meus caros (parte 02)...")