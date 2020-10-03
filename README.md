# BASE 64

The base 64 format is a serialization format used to save binary data to a printable format. What makes a bit difficult to implement, but also makes C a good candidate for this, is that the bits have to be grouped by 6 for serialization instead of 8.

Because most processors can't perform operations on less than a byte at a time, the grouping of 6 bits has to be done another way. In this implementation, we use bitwise AND masks to extract the interesting bits.

This implementation was inspired by [this article](https://www.pixelstech.net/article/1457585550-How-does-Base64-work) which I found while browsing reddit :smile:

### METADATA

Field | Value
--- | ---
:pencil: Contributors | roadelou
:email: Contacts | 
:date: Creation Date | 2020-10-03
:bulb: Language | Markdown Document

### EOF
