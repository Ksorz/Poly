import pyowm
owm = pyowm.OWM(input('Enter API key:').strip(), language="ru")
_city = None
while True:
    if _city is None:
        _city = input('\nКакой город? ')
    if _city == 'q':
        break
    try:
        observation = owm.weather_at_place(_city)
        w = observation.get_weather()
        deg = round(w.get_temperature('celsius')['temp'])
        print('\nВ городе ' + _city + ', сейчас ' + w.get_detailed_status())
        print('Температура ' + str(deg))
        if deg > 20:
            print('Очень тепло')
        elif deg > 10:
            print('Не очень тепло')
        else:
            print('Капец дубак')
        _city = None
    except:
        _city = input('Не могу найти, пробуй снова: ')
