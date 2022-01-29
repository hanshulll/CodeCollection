import wordcloud
from matplotlib import pyplot as plt


def generate_cloud(file_content):
    punctuations = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''

    uninteresting_words = ["the", "a", "to", "if", "is", "it", "of", "and", "or", "an", "as", "i", "me", "my", "we",
                           "our", "ours", "you", "your", "yours", "he", "she", "him", "his", "her", "hers", "its",
                           "they", "them", "their", "what", "which", "who", "whom", "this", "that", "am", "are", "was",
                           "were", "be", "been", "being", "have", "has", "had", "do", "does", "did", "but", "at", "by",
                           "with", "from", "here", "when", "where", "how", "all", "any", "both", "each", "few", "more",
                           "some", "such", "no", "nor", "too", "very", "can", "will", "just"]
    d = {}
    st = ""
    for i in file_content:
        if i in punctuations:
            continue
        st = st + i.lower()

    for i in st.split():
        if i not in uninteresting_words:
            d[i] = d.get(i, 0) + 1

    cloud = wordcloud.WordCloud()
    cloud.generate_from_frequencies(d)

    return cloud.to_array()

  
myimage = generate_cloud(input())
plt.imshow(myimage)
plt.axis('off')
plt.show()
