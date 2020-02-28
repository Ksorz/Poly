import telebot
bot = telebot.TeleBot(input('Enter API key:').strip())


@bot.message_handler(content_types=['text'])
def send_echo(message):
    # bot.reply_to(message, message.text)
    bot.send_message(message.chat.id, message.text)


bot.polling(none_stop=True)
