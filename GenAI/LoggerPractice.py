# LoggerPractice.py
import logging

logger = logging.getLogger(__name__)
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')

def divide(a, b):
    try:
        result = a / b
        logger.info('Divide Successful')
        return result
    except ZeroDivisionError:
        logger.error('Zero Divison Error!')
        return None
    
print(divide(100, 10))
print(divide(100, 0))